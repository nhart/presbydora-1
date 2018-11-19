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
  $form['presbydora_access_bypass_pids'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('PIDs to allow bypass download access check'),
    '#description' => t('List of collections that will bypass permission checks for datastream download.'),
    '#default_value' => variable_get('presbydora_access_bypass_pids'),
    '#size' => 10,
    '#options' => get_available_collections(),
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
function get_available_collections() {
  $tuque = islandora_get_tuque_connection();
  $options = array();
  $query = <<<EOQ
SELECT ?object ?label WHERE
  {
    ?object <fedora-model:hasModel> <info:fedora/islandora:collectionCModel>.
    ?object <fedora-model:label> ?label .
  }
EOQ;

  $results = $tuque->repository->ri->sparqlQuery($query);
  foreach ($results as $result) {
    $label = $result['label']['value'];
    $value = $result['object']['value'];
    $options[$value] = "$label: $value";
  }

  return $options;
}
