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
  $qp->solrParams['fq'] = '';
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
    try {
      if (!empty($results[0]['solr_doc']['ancestors_ms'])) {
        $ancestors = $results[0]['solr_doc']['ancestors_ms'];
      }
      // @note Extract constituencies and merge into one array. This is needed in
      // the case of a compound object that belongs to an exempted collection.
      // i.e. the compound children do not have an ancestors_ms field that will
      // relate to the exempted collection.
      if (!empty($results[0]['solr_doc']['RELS_EXT_isConstituentOf_uri_ms'])) {
        $constituencies = $results[0]['solr_doc']['RELS_EXT_isConstituentOf_uri_ms'];
        foreach ($constituencies as &$constituency) {
          // Remove info:fedora/.
          $constituency = substr($constituency, 12);
          $cons_parents = presbydora_get_ancestors($constituency);
          $ancestors = array_merge($ancestors, $cons_parents);
        }
      }
    }
    catch (Exception $e) {
      // Object has no ancestors.
    }
  }
  return $ancestors;
}
