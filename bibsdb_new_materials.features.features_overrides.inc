<?php
/**
 * @file
 * bibsdb_new_materials.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function bibsdb_new_materials_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_instance
  $overrides["field_instance.node-new_materials-field_ting_new_materials_items.default_value|0|value"] = 35;

 return $overrides;
}
