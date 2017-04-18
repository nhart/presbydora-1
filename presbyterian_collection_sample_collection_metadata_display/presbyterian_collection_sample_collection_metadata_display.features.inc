<?php
/**
 * @file
 * presbyterian_collection_sample_collection_metadata_display.features.inc
 */

/**
 * Implements hook_islandora_solr_metadata_configurations_default_fields().
 */
function presbyterian_collection_sample_collection_metadata_display_islandora_solr_metadata_configurations_default_fields() {
 return array(
  'collection' => array(
    'fields' => array(),
    'cmodels' => array(
      'islandora:collectionCModel' => array(
        'cmodel' => 'islandora:collectionCModel',
      ),
    ),
    'description' => array(
      'description_field' => 'mods_abstract_ms',
      'description_label' => '',
      'description_data' => array(
        'truncation' => array(
          'truncation_type' => 'whole_field_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 1,
          'min_wordsafe_length' => 1,
        ),
      ),
    ),
    'name' => 'Collection',
  ),
);
}
