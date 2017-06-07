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
      'description' => 'Reorignaizes objects based on csv',
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
  );
}

/**
 * Lift expired embargoes.
 */
function drush_presbydora_collection_reorganize_batch() {
  module_load_include('inc', 'islandora', 'includes/utilities');
  $path = drush_get_option('path');
  $pids = array_map('str_getcsv', file($path));
  $operations = array();


  foreach ($pids as $i_row => $row) {
    //skip column headers
    if ($i_row == 0) {
      continue;
    }
    $pid = NULL;
    $collections = array();
    foreach ($row as $i_column => $column) {
      $column = trim($column);
      //first column is the PID of the object to add to the collections
      if ($i_column == 0) {
        if (!islandora_is_valid_pid($column)) {
          drush_set_error("PID: $column is invalid");
          return FALSE;
        }
        $pid = $column;
      }
      //3rd column onward is the collection PIDs to add the object to.
      elseif ($i_column > 2 && !empty($column)) {
        if (!islandora_is_valid_pid($column)) {
          drush_set_error("PID: $column is invalid");
          return FALSE;
        }
        $collections[$column] = $column;
      }
    }

    $operations[] = array('presbydora_collection_reorganize_batch_operation', array(
        $pid,
        $collections,
    ));
  }
  $batch = array(
    'operations' => $operations,
  );
  batch_set($batch);
  drush_backend_batch_process();
}

function presbydora_collection_reorganize_batch_operation($pid, $collections, &$context) {
  if (!isset($context['sandbox']['good_collections'])) {
    $context['sandbox']['good_collections'] = array();
  }
  $object = islandora_object_load($pid);
  if ($object) {
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
        $object->relationships->remove(FEDORA_RELS_EXT_URI, 'isMemberOfCollection', $collection_pid);
        $object->relationships->add(FEDORA_RELS_EXT_URI, 'isMemberOfCollection', $collection_pid);
        drush_print("Added $pid to $collection_pid");
      }
    }
  }
  else {
    drush_set_error("Could not load object: $pid");
    return FALSE;
  }
}
