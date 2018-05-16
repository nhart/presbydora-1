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
