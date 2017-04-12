<?php
/**
 * @file
 * presbyterian_collection_page_layout.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function presbyterian_collection_page_layout_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'islandora_collection_search_advanced_search_alter';
  $strongarm->value = 0;
  $export['islandora_collection_search_advanced_search_alter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'islandora_collection_search_all_pages';
  $strongarm->value = 1;
  $export['islandora_collection_search_all_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'islandora_collection_search_ancestor_field';
  $strongarm->value = 'ancestors_ms';
  $export['islandora_collection_search_ancestor_field'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'islandora_collection_search_display_label';
  $strongarm->value = 1;
  $export['islandora_collection_search_display_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'islandora_collection_search_gsearch_endpoint';
  $strongarm->value = 'http://localhost:8080/fedoragsearch/rest';
  $export['islandora_collection_search_gsearch_endpoint'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'islandora_collection_search_gsearch_user';
  $strongarm->value = 'fedoraAdmin';
  $export['islandora_collection_search_gsearch_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'islandora_collection_search_retain_search_values';
  $strongarm->value = 0;
  $export['islandora_collection_search_retain_search_values'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'islandora_collection_search_searchable_collections';
  $strongarm->value = array(
    'islandora:audio_collection' => 'islandora:audio_collection',
    'islandora:sp_basic_image_collection' => 'islandora:sp_basic_image_collection',
    'islandora:binary_object_collection' => 'islandora:binary_object_collection',
    'islandora:bookCollection' => 'islandora:bookCollection',
    'ir:citationCollection' => 'ir:citationCollection',
    'islandora:compound_collection' => 'islandora:compound_collection',
    'islandora:sp_document_collection' => 'islandora:sp_document_collection',
    'islandora:entity_collection' => 'islandora:entity_collection',
    'islandora:featured_collection' => 'islandora:featured_collection',
    'islandora:sp_large_image_collection' => 'islandora:sp_large_image_collection',
    'islandora:manuscriptCollection' => 'islandora:manuscriptCollection',
    'islandora:newspaper_collection' => 'islandora:newspaper_collection',
    'islandora:sp_pdf_collection' => 'islandora:sp_pdf_collection',
    'islandora:sample_collection' => 'islandora:sample_collection',
    'islandora:serial_collection' => 'islandora:serial_collection',
    'islandora:root' => 'islandora:root',
    'islandora:transformCollection' => 'islandora:transformCollection',
    'islandora:video_collection' => 'islandora:video_collection',
  );
  $export['islandora_collection_search_searchable_collections'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pm_existing_pages_disabled_islandora_object_existing_page';
  $strongarm->value = FALSE;
  $export['pm_existing_pages_disabled_islandora_object_existing_page'] = $strongarm;

  return $export;
}
