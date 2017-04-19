<?php
/**
 * @file
 * presbyterian_collection_page_layout.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function presbyterian_collection_page_layout_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'collection_banner';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'islandora_solr';
  $view->human_name = 'Collection Banner';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Collection Banner';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Islandora Solr: PID */
  $handler->display->display_options['fields']['PID']['id'] = 'PID';
  $handler->display->display_options['fields']['PID']['table'] = 'islandora_solr';
  $handler->display->display_options['fields']['PID']['field'] = 'PID';
  $handler->display->display_options['fields']['PID']['label'] = '';
  $handler->display->display_options['fields']['PID']['exclude'] = TRUE;
  $handler->display->display_options['fields']['PID']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['PID']['link_to_object'] = 0;
  /* Field: Islandora Solr: fgs_label_ms */
  $handler->display->display_options['fields']['fgs_label_ms']['id'] = 'fgs_label_ms';
  $handler->display->display_options['fields']['fgs_label_ms']['table'] = 'islandora_solr';
  $handler->display->display_options['fields']['fgs_label_ms']['field'] = 'fgs_label_ms';
  $handler->display->display_options['fields']['fgs_label_ms']['label'] = '';
  $handler->display->display_options['fields']['fgs_label_ms']['exclude'] = TRUE;
  $handler->display->display_options['fields']['fgs_label_ms']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['fgs_label_ms']['link_to_object'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div>
  <img title = "[fgs_label_ms]" src="/islandora/object/[PID]/datastream/MEDIUM_SIZE/view"/>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Contextual filter: Islandora Solr: PID */
  $handler->display->display_options['arguments']['PID']['id'] = 'PID';
  $handler->display->display_options['arguments']['PID']['table'] = 'islandora_solr';
  $handler->display->display_options['arguments']['PID']['field'] = 'PID';
  $handler->display->display_options['arguments']['PID']['default_action'] = 'default';
  $handler->display->display_options['arguments']['PID']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['PID']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['PID']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['PID']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['PID']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['collection_banner'] = array(
    t('Master'),
    t('Collection Banner'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<div>
  <img title = "[fgs_label_ms]" src="/islandora/object/[PID]/datastream/MEDIUM_SIZE/view"/>
</div>'),
    t('All'),
    t('Block'),
  );
  $export['collection_banner'] = $view;

  $view = new view();
  $view->name = 'list_style_field_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'islandora_solr';
  $view->human_name = 'List Style Field View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'List Style Field View';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Islandora Solr: fgs_label_ms */
  $handler->display->display_options['fields']['fgs_label_ms']['id'] = 'fgs_label_ms';
  $handler->display->display_options['fields']['fgs_label_ms']['table'] = 'islandora_solr';
  $handler->display->display_options['fields']['fgs_label_ms']['field'] = 'fgs_label_ms';
  $handler->display->display_options['fields']['fgs_label_ms']['label'] = 'Title';
  $handler->display->display_options['fields']['fgs_label_ms']['element_type'] = 'div';
  $handler->display->display_options['fields']['fgs_label_ms']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['fgs_label_ms']['link_to_object'] = 1;
  /* Field: Islandora Solr: dc.description */
  $handler->display->display_options['fields']['dc.description']['id'] = 'dc.description';
  $handler->display->display_options['fields']['dc.description']['table'] = 'islandora_solr';
  $handler->display->display_options['fields']['dc.description']['field'] = 'dc.description';
  $handler->display->display_options['fields']['dc.description']['label'] = 'Description';
  $handler->display->display_options['fields']['dc.description']['element_type'] = 'div';
  $handler->display->display_options['fields']['dc.description']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['dc.description']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc.description']['link_to_object'] = 0;
  /* Field: Islandora Solr: fgs_createdDate_dt */
  $handler->display->display_options['fields']['fgs_createdDate_dt']['id'] = 'fgs_createdDate_dt';
  $handler->display->display_options['fields']['fgs_createdDate_dt']['table'] = 'islandora_solr';
  $handler->display->display_options['fields']['fgs_createdDate_dt']['field'] = 'fgs_createdDate_dt';
  $handler->display->display_options['fields']['fgs_createdDate_dt']['label'] = 'Date Created';
  $handler->display->display_options['fields']['fgs_createdDate_dt']['element_type'] = 'div';
  $handler->display->display_options['fields']['fgs_createdDate_dt']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['fgs_createdDate_dt']['link_to_object'] = 0;
  $handler->display->display_options['fields']['fgs_createdDate_dt']['date_format'] = 'long';
  /* Contextual filter: Islandora Solr: PID */
  $handler->display->display_options['arguments']['PID']['id'] = 'PID';
  $handler->display->display_options['arguments']['PID']['table'] = 'islandora_solr';
  $handler->display->display_options['arguments']['PID']['field'] = 'PID';
  $handler->display->display_options['arguments']['PID']['default_action'] = 'default';
  $handler->display->display_options['arguments']['PID']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['PID']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['PID']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['PID']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['PID']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['list_style_field_view'] = array(
    t('Master'),
    t('List Style Field View'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Title'),
    t('Description'),
    t('Date Created'),
    t('All'),
    t('Block'),
  );
  $export['list_style_field_view'] = $view;

  return $export;
}
