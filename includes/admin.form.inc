<?php

/**
 * @file
 * Admin form for this module.
 */

/**
 * Admin form for presbydora.
 *
 * @param array $form
 *   Form object.
 * @param array $form_state
 *   Form values.
 *
 * @return array
 *   A renderable array available as a multi-select box.
 */
function presbydora_admin_form(array $form, array &$form_state) {
  $tableselect = presbydora_build_tableselect();
  $form['presbydora_access_bypass_pids'] = array(
    '#type' => 'tableselect',
    '#header' => $tableselect['header'],
    '#options' => $tableselect['rows'],
    '#multiple' => TRUE,
    '#default_value' => variable_get('presbydora_access_bypass_pids', ''),
  );

  $form['presbydora_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configurations'),
  );

  return $form;
}

/**
 * Submit handler for wrlcdora admin form.
 *
 * @param array $form
 *   Form object.
 * @param array $form_state
 *   Form values.
 */
function presbydora_admin_form_submit(array $form, array $form_state) {
  module_load_include('inc', 'islandora', 'includes/utilities');
  $values = $form_state['values'];
  $pids = $values['presbydora_access_bypass_pids'];
  if (!empty($pids)) {
    foreach ($pids as $pid) {
      if (!islandora_is_valid_pid($pid)) {
        drupal_set_message(t('@pid is not a valid pid!', array('@pid' => $pid)), 'error');
      }
    }
  }
  variable_set('presbydora_access_bypass_pids', $pids);
  drupal_set_message(t('The configuration options have been saved.'), 'status');
}

/**
 * Helper function to select objects of a certain model type.
 *
 * @return array
 *   An array of key value pairs where the key is the pid and value is label.
 */
function presbydora_get_available_collections() {
  $collections = islandora_basic_collection_get_collections();
  $options = array();

  foreach ($collections as $collection) {
    $label = $collection['label'];
    $value = $collection['pid'];
    $options[$value] = "$label";
  }

  return $options;
}

/**
 * Helper function to build tableselect for presbydora admin menu.
 *
 * @return array
 *   An array of key value pairs containing header and row values.
 */
function presbydora_build_tableselect() {
  $collections = presbydora_get_available_collections();
  $header = array(
    'title' => t('Label'),
    'type' => t('PID'),
  );

  $rows = array();
  foreach ($collections as $pid => $label) {
    $rows[$pid] = array(
      'title' => $label,
      'type' => $pid,
    );
  }
  $tableselect = array();
  $tableselect['header'] = $header;
  $tableselect['rows'] = $rows;

  return $tableselect;
}
