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
  $default_values = variable_get('presbydora_access_bypass_pids', array());
  $default_values = array_filter($default_values);

  $form['presbydora_access_bypass_pids'] = array(
    '#type' => 'tableselect',
    '#header' => $tableselect['header'],
    '#options' => $tableselect['rows'],
    '#multiple' => TRUE,
    '#default_value' => $default_values,
  );

  $form['presbydora_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration'),
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
  $pids = array();
  if (isset($values['presbydora_access_bypass_pids'])) {
    $pids = array_filter($values['presbydora_access_bypass_pids']);
  }
  variable_set('presbydora_access_bypass_pids', $pids);
  drupal_set_message(t('The configuration options have been saved.'), 'status');
}

/**
 * Helper function to build tableselect for presbydora admin menu.
 *
 * @return array
 *   An array of key value pairs containing header and row values.
 */
function presbydora_build_tableselect() {
  $rows = islandora_basic_collection_get_collections();
  $header = array(
    'label' => t('Label'),
    'pid' => t('PID'),
  );

  $tableselect = array();
  $tableselect['header'] = $header;
  $tableselect['rows'] = $rows;

  return $tableselect;
}
