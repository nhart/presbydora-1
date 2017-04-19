<?php
/**
 * @file
 * phs_metadata_configs.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function phs_metadata_configs_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'islandora_metadata_display';
  $strongarm->value = 'islandora_solr_metadata';
  $export['islandora_metadata_display'] = $strongarm;

  return $export;
}
