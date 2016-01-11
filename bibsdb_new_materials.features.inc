<?php
/**
 * @file
 * bibsdb_new_materials.features.inc
 */

/**
 * Implements hook_field_default_field_instances_alter().
 */
function bibsdb_new_materials_field_default_field_instances_alter(&$data) {
  if (isset($data['node-new_materials-field_ting_new_materials_items'])) {
    $data['node-new_materials-field_ting_new_materials_items']['default_value'][0]['value'] = 35; /* WAS: 10 */
  }
}
