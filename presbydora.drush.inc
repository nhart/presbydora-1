<?php

/**
 * @file
 * Implementation of Drush hooks.
 */

/**
 * Implements hook_drush_command().
 */
function presbydora_drush_command() {
  return array(
    'presbydora_collection_reorganize_batch' => array(
      'description' => 'Reorganizes objects based on csv',
      'drupal dependencies' => array(
        'islandora',
      ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
      'options' => array(
        'path' => array(
          'description' => dt('The full path to the CSV.'),
          'required' => TRUE,
        ),
      ),
    ),
    'presbydora_generate_duplicate_datastream_curl_purge' => array(
      'description' => dt('Return curl command to delete duplicate DS versions.'),
      'options' => array(),
      'aliases' => array('lwfp'),
    ),
  );
}

/**
 * Command callback; process csv batch.
 */
function drush_presbydora_collection_reorganize_batch() {
  module_load_include('inc', 'islandora', 'includes/utilities');
  $path = drush_get_option('path');
  $pids = array_map('str_getcsv', file($path));
  $operations = array();

  foreach ($pids as $i_row => $row) {
    // Skip column headers.
    if ($i_row == 0) {
      continue;
    }
    $pid = NULL;
    $collections = array();
    foreach ($row as $i_column => $column) {
      $column = trim($column);
      // First column is the PID of the object to add to the collections.
      if ($i_column == 0) {
        if (!islandora_is_valid_pid($column)) {
          drush_set_error("PID: $column is invalid");
          return FALSE;
        }
        $pid = $column;
      }
      // 3rd column onward is the collection PIDs to add the object to.
      elseif ($i_column > 2 && !empty($column)) {
        if (!islandora_is_valid_pid($column)) {
          drush_set_error("PID: $column is invalid");
          return FALSE;
        }
        $collections[$column] = $column;
      }
    }

    $operations[] = array(
      'presbydora_collection_reorganize_batch_operation',
      array(
        $pid,
        $collections,
      ),
    );
  }
  $batch = array(
    'operations' => $operations,
  );
  batch_set($batch);
  drush_backend_batch_process();
}

/**
 * Batch operation; Add isMemberOfCollection relations to PID.
 */
function presbydora_collection_reorganize_batch_operation($pid, $collections, &$context) {
  if (!isset($context['sandbox']['good_collections'])) {
    $context['sandbox']['good_collections'] = array();
  }
  $object = islandora_object_load($pid);
  if ($object) {
    $rels = $object->relationships;
    $rels->autoCommit = FALSE;
    $commit = FALSE;
    foreach ($collections as $collection_pid) {
      if (!isset($context['sandbox']['good_collections'][$collection_pid])) {
        $collection = islandora_object_load($collection_pid);
        if ($collection) {
          $context['sandbox']['good_collections'][$collection_pid] = $collection_pid;
        }
        else {
          drush_set_error("Could not load collection object: $collection_pid");
          return FALSE;
        }
      }
      if (isset($context['sandbox']['good_collections'][$collection_pid])) {
        $commit = TRUE;
        $rels->remove(FEDORA_RELS_EXT_URI, 'isMemberOfCollection', $collection_pid);
        $rels->add(FEDORA_RELS_EXT_URI, 'isMemberOfCollection', $collection_pid);
        drush_print("Added $pid to $collection_pid");
      }
    }
    if ($commit == TRUE) {
      $rels->commitRelationships();
    }
  }
  else {
    drush_set_error("Could not load object: $pid");
    return FALSE;
  }
}

/**
 * Batch preprocessing drush script.
 */
function drush_presbydora_generate_duplicate_datastream_curl_purge() {
  drupal_static_reset('islandora_get_tuque_connection');
  $connection = islandora_get_tuque_connection();
  $pids = array("");
  $dsids = array("POLICY", "RELS-INT", "RELS-EXT");
  foreach ($pids as $pid) {
    $object = islandora_object_load($pid);
    dd($pid, 'pid');
    $track = array();
    foreach ($dsids as $dsid) {
      if (isset($object[$dsid])) {
        dd($dsid, 'dsid');

        $version_array = array();
        foreach ($object[$dsid] as $version => $ds) {
          $date = $ds->createdDate->__toString();
          dd($date, 'version');
          if (in_array($ds->content, $track)) {
            $version_array[$version] = $date;
          }
          else {
            $track[] = $ds->content;
          }
        }

        $start_date = NULL;
        foreach ($version_array as $version => $date) {
          if ($start_date == NULL) {
            $start_date = $date;
          }
          if(isset($version_array[$version + 1])) {
            continue;
          }
          else {
            $end_date = $date;
            drush_log('curl -X DELETE -u fedoraAdmin:password "localhost:8080/fedora/objects/'. $object->id .'/datastreams/' . $dsid . '?startDT='. $end_date .'&endDT='. $start_date .'"');
            $start_date = NULL;
          }
        }
      }
    }
  }
}
