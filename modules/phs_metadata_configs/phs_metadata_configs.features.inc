<?php
/**
 * @file
 * phs_metadata_configs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function phs_metadata_configs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_islandora_solr_metadata_configurations_default_fields().
 */
function phs_metadata_configs_islandora_solr_metadata_configurations_default_fields() {
 return array(
  'PageMODS' => array(
    'fields' => array(
      'mods_titleInfo_title_ms' => array(
        'solr_field' => 'mods_titleInfo_title_ms',
        'weight' => 2,
        'data' => 'a:3:{s:13:"display_label";s:5:"Title";s:9:"hyperlink";i:1;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Title',
        'hyperlink' => 1,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_abstract_ms' => array(
        'solr_field' => 'mods_abstract_ms',
        'weight' => 3,
        'data' => 'a:3:{s:13:"display_label";s:11:"Description";s:9:"hyperlink";i:0;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Description',
        'hyperlink' => 0,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'OCR_t' => array(
        'solr_field' => 'OCR_t',
        'weight' => 4,
        'data' => 'a:3:{s:13:"display_label";s:13:"Transcription";s:9:"hyperlink";i:0;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Transcription',
        'hyperlink' => 0,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_name_role_phs_ms' => array(
        'solr_field' => 'mods_name_role_phs_ms',
        'weight' => 5,
        'data' => 'a:3:{s:13:"display_label";s:10:"Creator(s)";s:9:"hyperlink";i:1;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Creator(s)',
        'hyperlink' => 1,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_originInfo_dateCreated_ms' => array(
        'solr_field' => 'mods_originInfo_dateCreated_ms',
        'weight' => 6,
        'data' => 'a:3:{s:13:"display_label";s:12:"Date Created";s:9:"hyperlink";i:1;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Date Created',
        'hyperlink' => 1,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_subject_name_phs_ms' => array(
        'solr_field' => 'mods_subject_name_phs_ms',
        'weight' => 7,
        'data' => 'a:3:{s:13:"display_label";s:15:"Name Subject(s)";s:9:"hyperlink";i:1;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Name Subject(s)',
        'hyperlink' => 1,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_subject_topic_ms' => array(
        'solr_field' => 'mods_subject_topic_ms',
        'weight' => 8,
        'data' => 'a:3:{s:13:"display_label";s:18:"Topical Subject(s)";s:9:"hyperlink";i:1;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Topical Subject(s)',
        'hyperlink' => 1,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_subject_temporal_ms' => array(
        'solr_field' => 'mods_subject_temporal_ms',
        'weight' => 9,
        'data' => 'a:3:{s:13:"display_label";s:19:"Temporal Subject(s)";s:9:"hyperlink";i:1;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Temporal Subject(s)',
        'hyperlink' => 1,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_subject_geographic_ms' => array(
        'solr_field' => 'mods_subject_geographic_ms',
        'weight' => 10,
        'data' => 'a:3:{s:13:"display_label";s:21:"Geographic Subject(s)";s:9:"hyperlink";i:1;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Geographic Subject(s)',
        'hyperlink' => 1,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_genre_ms' => array(
        'solr_field' => 'mods_genre_ms',
        'weight' => 11,
        'data' => 'a:3:{s:13:"display_label";s:5:"Genre";s:9:"hyperlink";i:1;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Genre',
        'hyperlink' => 1,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_physicalDescription_form_ms' => array(
        'solr_field' => 'mods_physicalDescription_form_ms',
        'weight' => 12,
        'data' => 'a:3:{s:13:"display_label";s:4:"Form";s:9:"hyperlink";i:1;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Form',
        'hyperlink' => 1,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_subject_hierarchicalGeographic_continent_ms' => array(
        'solr_field' => 'mods_subject_hierarchicalGeographic_continent_ms',
        'weight' => 13,
        'data' => 'a:3:{s:13:"display_label";s:9:"Continent";s:9:"hyperlink";i:1;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Continent',
        'hyperlink' => 1,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_subject_hierarchicalGeographic_country_ms' => array(
        'solr_field' => 'mods_subject_hierarchicalGeographic_country_ms',
        'weight' => 14,
        'data' => 'a:3:{s:13:"display_label";s:7:"Country";s:9:"hyperlink";i:1;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Country',
        'hyperlink' => 1,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_subject_hierarchicalGeographic_region_ms' => array(
        'solr_field' => 'mods_subject_hierarchicalGeographic_region_ms',
        'weight' => 15,
        'data' => 'a:3:{s:13:"display_label";s:6:"Region";s:9:"hyperlink";i:1;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Region',
        'hyperlink' => 1,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_subject_hierarchicalGeographic_state_ms' => array(
        'solr_field' => 'mods_subject_hierarchicalGeographic_state_ms',
        'weight' => 16,
        'data' => 'a:3:{s:13:"display_label";s:5:"State";s:9:"hyperlink";i:1;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'State',
        'hyperlink' => 1,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_subject_hierarchicalGeographic_city_ms' => array(
        'solr_field' => 'mods_subject_hierarchicalGeographic_city_ms',
        'weight' => 17,
        'data' => 'a:3:{s:13:"display_label";s:4:"City";s:9:"hyperlink";i:1;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'City',
        'hyperlink' => 1,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_subject_hierarchicalGeographic_citySection_ms' => array(
        'solr_field' => 'mods_subject_hierarchicalGeographic_citySection_ms',
        'weight' => 18,
        'data' => 'a:3:{s:13:"display_label";s:12:"City Section";s:9:"hyperlink";i:1;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'City Section',
        'hyperlink' => 1,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_subject_hierarchicalGeographic_island_ms' => array(
        'solr_field' => 'mods_subject_hierarchicalGeographic_island_ms',
        'weight' => 19,
        'data' => 'a:3:{s:13:"display_label";s:6:"Island";s:9:"hyperlink";i:1;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Island',
        'hyperlink' => 1,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_accessCondition_use_and_reproduction_ms' => array(
        'solr_field' => 'mods_accessCondition_use_and_reproduction_ms',
        'weight' => 20,
        'data' => 'a:3:{s:13:"display_label";s:13:"Rights Status";s:9:"hyperlink";i:1;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Rights Status',
        'hyperlink' => 1,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_accessCondition_rights_statement_ms' => array(
        'solr_field' => 'mods_accessCondition_rights_statement_ms',
        'weight' => 21,
        'data' => 'a:3:{s:13:"display_label";s:16:"Rights Statement";s:9:"hyperlink";i:0;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Rights Statement',
        'hyperlink' => 0,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_identifier_local_ms' => array(
        'solr_field' => 'mods_identifier_local_ms',
        'weight' => 22,
        'data' => 'a:3:{s:13:"display_label";s:18:"Identifier (local)";s:9:"hyperlink";i:0;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Identifier (local)',
        'hyperlink' => 0,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'PID' => array(
        'solr_field' => 'PID',
        'weight' => 23,
        'data' => 'a:3:{s:13:"display_label";s:27:"PID (Persistent Identifier)";s:9:"hyperlink";i:0;s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'PID (Persistent Identifier)',
        'hyperlink' => 0,
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
    ),
    'cmodels' => array(
      'islandora:pageCModel' => array(
        'cmodel' => 'islandora:pageCModel',
      ),
    ),
    'description' => array(
      'description_field' => NULL,
      'description_label' => NULL,
      'description_data' => NULL,
    ),
    'name' => 'Page MODS',
  ),
  'collection' => array(
    'fields' => array(
      'mods_titleInfo_title_ms' => array(
        'solr_field' => 'mods_titleInfo_title_ms',
        'weight' => 1,
        'data' => 'a:4:{s:13:"display_label";s:5:"Title";s:9:"hyperlink";i:0;s:15:"uri_replacement";s:0:"";s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Title',
        'hyperlink' => 0,
        'uri_replacement' => '',
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
      'mods_abstract_ms' => array(
        'solr_field' => 'mods_abstract_ms',
        'weight' => 2,
        'data' => 'a:4:{s:13:"display_label";s:11:"Description";s:9:"hyperlink";i:0;s:15:"uri_replacement";s:0:"";s:10:"truncation";a:5:{s:15:"truncation_type";s:21:"separate_value_option";s:10:"max_length";i:0;s:9:"word_safe";i:0;s:8:"ellipsis";i:0;s:19:"min_wordsafe_length";i:1;}}',
        'display_label' => 'Description',
        'hyperlink' => 0,
        'uri_replacement' => '',
        'truncation' => array(
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
    ),
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
          'truncation_type' => 'separate_value_option',
          'max_length' => 0,
          'word_safe' => 0,
          'ellipsis' => 0,
          'min_wordsafe_length' => 1,
        ),
      ),
    ),
    'name' => 'Collection',
  ),
);
}
