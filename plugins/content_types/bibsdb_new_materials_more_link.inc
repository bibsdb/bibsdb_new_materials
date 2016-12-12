<?php

/**
 * @file
 * NOT USED ANY MORE BUT I GET AN ERROR IF I DELETE IT
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
 
}

/**
 * Enable admin settings page.
 */
function bibsdb_new_materials_content_type_edit_form($form, &$form_state) {
	return $form;
}