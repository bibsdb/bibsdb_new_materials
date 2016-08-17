<?php

/**
 * @file
 * This plugin generates a View more link below the result when frontpages are shown.
 */
$plugin = array(
	'title' => t('Bibsdb new materials more link'),
	'description' => t('Link to more materials in the same query'),
	'single' => TRUE,
	'edit form' => 'bibsdb_new_materials_content_type_edit_form',
	'render callback' => 'bibsdb_new_materials_content_type_render',
	'category' => t('Bibsdb'),
	'required context' => array(new ctools_context_required(t('New Materials'), 'node')),
	);

/**
 * Render the ting new materials results results amount block.
 */
function bibsdb_new_materials_content_type_render($subtype, $conf, $panel_args, $context) {
  // Define the return block.
	$block = new stdClass();

  // Check if context exists.
	if (isset($context[0]->data) && $context[0]->data->type == 'new_materials') {
    // Get the node.
		$node = $context[0]->data;
		$node_wrapper = entity_metadata_wrapper('node', $node);

		$covers_mode = $node_wrapper->field_ting_new_materials_covers->value();

		if ($covers_mode) {

			$query = $node_wrapper->field_ting_new_materials_search->value();
			$query_url_encoded = rawurlencode($query);

    	 // Set default page result.
			$content = array(
        '#type'  => 'link',
        '#title' => "Se flere forslag",
        '#href'  => "/search/ting/" . $query,
				);

       // Set block content.
			$block->content = $content;
		}
	}
	return $block;
}

/**
 * Enable admin settings page.
 */
function bibsdb_new_materials_content_type_edit_form($form, &$form_state) {
  return $form;
}