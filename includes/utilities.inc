<?php

/**
 * @file
 * Helper functions used by this module.
 */

/**
 * Renders the TEXT tab.
 *
 * @pararm AbstractObject $object
 *   The object the TEXT belongs to.
 *
 * @return array
 *   A renderable array representing the tab.
 */
function presbydora_text_view(AbstractObject $object) {
  return array(
    'link' => array(
      '#markup' => l(t('Download TEXT'), "islandora/object/{$object->id}/datastream/TEXT/download"),
    ),
    'text' => array(
      '#markup' => check_markup($object['TEXT']->content, 'filtered_html'),
    ),
  );
}

/**
 * Function that will return an array of ancestors related to the pid param.
 *
 * @param string $pid
 *   Object pid to find ancestors of.
 *
 * @return array
 *   Array containing ancestors' PIDs.
 */
function presbydora_get_ancestors($pid) {
  $qp = new IslandoraSolrQueryProcessor();
  $query = format_string('PID:"!pid"',
    array('!pid' => $pid)
  );
  $qp->buildQuery($query);

  $constituent_filter = array();
  if (variable_get('islandora_compound_object_hide_child_objects_solr', TRUE)) {
    $fq = variable_get('islandora_compound_object_solr_fq', '-RELS_EXT_isConstituentOf_uri_mt:[* TO *]');
    if (!empty($fq)) {
      $constituent_filter[] = $fq;
    }
  }
  $qp->solrParams['fq'] = array_diff($qp->solrParams['fq'], $constituent_filter);
  $qp->solrParams['facet'] = 'false';
  $qp->solrLimit = 1;
  $qp->executeQuery(FALSE);

  try {
    $results = $qp->islandoraSolrResult['response']['objects'];
    $total_results = $qp->islandoraSolrResult['response']['numFound'];
  }
  catch (Exception $e) {
    watchdog_exception('Presbydora', $e, 'Got an exception while searching for object ancestors and constituencies.', array(), WATCHDOG_ERROR);
    $results = array();
  }

  $ancestors = array();
  $constituencies = array();
  if ($total_results > 0) {
    if (isset($results[0]['solr_doc']['ancestors_ms'])) {
      $ancestors = $results[0]['solr_doc']['ancestors_ms'];
    }
    // @note Extract constituencies and merge into one array. This is needed in
    // the case of a compound object that belongs to an exempted collection.
    // i.e. the compound children do not have an ancestors_ms field that will
    // relate to the exempted collection.
    if (isset($results[0]['solr_doc']['RELS_EXT_isConstituentOf_uri_ms'])) {
      $constituencies = $results[0]['solr_doc']['RELS_EXT_isConstituentOf_uri_ms'];
      foreach ($constituencies as $constituency) {
        // Remove info:fedora/.
        $constituency_pid = substr($constituency, 12);
        // XXX: This can lead to a possible recursive loop. However, it has been
        // decided that, because this is an edge case, we will handle this
        // in the event it comes up. Blazegraph would help.
        $cons_parents = presbydora_get_ancestors($constituency_pid);
        $ancestors = array_merge($ancestors, $cons_parents);
      }
    }
  }
  return $ancestors;
}

/**
 * Custom validation for user password reset.
 *
 * This function is used to cover D7's security bug that reveals whether an
 * email or username is in use, see:
 * https://www.drupal.org/project/drupal/issues/1521996.
 */
function presbydora_user_pass_validate(&$form, &$form_state) {
  $name = trim($form_state['values']['name']);
  // Try to load by email.
  $users = user_load_multiple(array(), array('mail' => $name, 'status' => '1'));
  $account = reset($users);
  if (!$account) {
    // No success, try to load by name.
    $users = user_load_multiple(array(), array('name' => $name, 'status' => '1'));
    $account = reset($users);
  }
  if (isset($account->uid)) {
    form_set_value(array('#parents' => array('account')), $account, $form_state);
  }
  else {
    $form['#submit'] = array('presbydora_user_pass_submit');
  }
}

/**
 * Custom user password reset submit function.
 *
 * This function is used to cover D7's security bug that reveals whether an
 * email or username is in use, see:
 * https://www.drupal.org/project/drupal/issues/1521996.
 */
function presbydora_user_pass_submit($form, &$form_state) {
  drupal_set_message(t('Further instructions have been sent to your e-mail address.'));
  $form_state['redirect'] = 'user';
  return;
}
