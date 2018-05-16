<?php

/**
 * @file
 * Helper functions used by this module.
 */

/**
 * Return the contents of the TEXT datastream.
 *
 * @param AbstractObject $object
 *   A Fedora object containing a TEXT datastream.
 *
 * @return string
 *   The filtered output of TEXT datastream contents.
 */
function presbydora_display_text(AbstractObject $object) {
  return check_markup($object['TEXT']->content, 'filtered_html');
}

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
      '#markup' => presbydora_display_text($object),
    ),
  );
}
