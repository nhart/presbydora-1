<?php
/**
 * @file
 * presbyterian_collection_page_layout.pm_existing_pages.inc
 */

/**
 * Implements hook_pm_existing_pages_info().
 */
function presbyterian_collection_page_layout_pm_existing_pages_info() {
  $export = array();

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'islandora_object_existing_page';
  $pm_existing_page->label = 'Islandora Object Existing Page';
  $pm_existing_page->context = '';
  $pm_existing_page->paths = 'islandora/object/%islandora_object';
  $export['islandora_object_existing_page'] = $pm_existing_page;

  return $export;
}
