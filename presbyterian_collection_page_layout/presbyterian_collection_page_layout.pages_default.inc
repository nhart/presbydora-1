<?php
/**
 * @file
 * presbyterian_collection_page_layout.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function presbyterian_collection_page_layout_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_islandora_object_existing_page__panel_context_6d886748-85c4-4916-8635-e7b874820d24';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'islandora_object_existing_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Islandora Collection Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Is Collection Page',
            'php' => '      $object = menu_get_object(\'islandora_object\', 2);
      if ($object && in_array("islandora:collectionCModel", $object->models)) {
        return TRUE;
      }',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => 'collection-page-layout',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
        'hide_empty' => 0,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 1,
          1 => 'main-row',
          2 => 2,
          3 => 3,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'collection_header_region_left',
          1 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '74.98925701547807',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'collection_header_region',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'collection_header_region' => array(
        'type' => 'region',
        'title' => 'Collection Header Region',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'collection_header_bottom',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'collection_header_bottom' => array(
        'type' => 'region',
        'title' => 'Collection Header Bottom',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 0,
      ),
      'collection_header_region_left' => array(
        'type' => 'region',
        'title' => 'Collection Header Region Left',
        'width' => '25.010742984521926',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'collection_contents',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'collection_contents' => array(
        'type' => 'region',
        'title' => 'Collection Contents',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'collection_header_region' => NULL,
      'collection_header_bottom' => NULL,
      'collection_header_region_left' => NULL,
      'collection_contents' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1ae7b256-eaaa-4301-8b63-a5e5dc2f9f77';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'pm_existing_pages_islandora_object_existing_page__panel_context_6d886748-85c4-4916-8635-e7b874820d24';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-99f881e7-4278-4a36-bebc-52f85a0f4e6d';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'presbydora-presbydora_metadata_description';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'About this Collection',
    'override_title_heading' => 'h4',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '99f881e7-4278-4a36-bebc-52f85a0f4e6d';
  $display->content['new-99f881e7-4278-4a36-bebc-52f85a0f4e6d'] = $pane;
  $display->panels['center'][0] = 'new-99f881e7-4278-4a36-bebc-52f85a0f4e6d';
  $pane = new stdClass();
  $pane->pid = 'new-9df83c51-403e-46ee-a4b4-a5d79635a7ef';
  $pane->panel = 'collection_contents';
  $pane->type = 'pm_existing_pages';
  $pane->subtype = 'pm_existing_pages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    0 => 'task_id',
    'task_id' => 'islandora_object_existing_page',
    'override_title' => 1,
    'override_title_text' => '<none>',
    'override_title_heading' => 'h4',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9df83c51-403e-46ee-a4b4-a5d79635a7ef';
  $display->content['new-9df83c51-403e-46ee-a4b4-a5d79635a7ef'] = $pane;
  $display->panels['collection_contents'][0] = 'new-9df83c51-403e-46ee-a4b4-a5d79635a7ef';
  $pane = new stdClass();
  $pane->pid = 'new-60f24701-60e3-445c-9ff2-a068a9c9d6d7';
  $pane->panel = 'collection_header_bottom';
  $pane->type = 'block';
  $pane->subtype = 'islandora_collection_search-islandora_collection_search';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '<none>',
    'override_title_heading' => 'h4',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '60f24701-60e3-445c-9ff2-a068a9c9d6d7';
  $display->content['new-60f24701-60e3-445c-9ff2-a068a9c9d6d7'] = $pane;
  $display->panels['collection_header_bottom'][0] = 'new-60f24701-60e3-445c-9ff2-a068a9c9d6d7';
  $pane = new stdClass();
  $pane->pid = 'new-d1c46401-5344-4cd9-9a37-2d1502f0ceee';
  $pane->panel = 'collection_header_region';
  $pane->type = 'block';
  $pane->subtype = 'islandora_solr-display_switch';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '<none>',
    'override_title_heading' => 'h4',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd1c46401-5344-4cd9-9a37-2d1502f0ceee';
  $display->content['new-d1c46401-5344-4cd9-9a37-2d1502f0ceee'] = $pane;
  $display->panels['collection_header_region'][0] = 'new-d1c46401-5344-4cd9-9a37-2d1502f0ceee';
  $pane = new stdClass();
  $pane->pid = 'new-96c4e5b5-926f-4833-a17d-8aeda4ee366c';
  $pane->panel = 'collection_header_region_left';
  $pane->type = 'block';
  $pane->subtype = 'views-collection_banner-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '<none>',
    'override_title_heading' => 'h4',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '96c4e5b5-926f-4833-a17d-8aeda4ee366c';
  $display->content['new-96c4e5b5-926f-4833-a17d-8aeda4ee366c'] = $pane;
  $display->panels['collection_header_region_left'][0] = 'new-96c4e5b5-926f-4833-a17d-8aeda4ee366c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_islandora_object_existing_page__panel_context_6d886748-85c4-4916-8635-e7b874820d24'] = $handler;

  return $export;
}
