<?php


/**
* Implementation of hook_views_default_views().
**/
function ujf_personal_page_views_default_views() {
$view = new view();
$view->name = 'view_ujf_personal_page';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'UJF Personal Page';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'plus';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
$handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
$handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
$handler->display->display_options['pager']['options']['tags']['first'] = '« premier';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ précédent';
$handler->display->display_options['pager']['options']['tags']['next'] = 'suivant ›';
$handler->display->display_options['pager']['options']['tags']['last'] = 'dernier »';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
/* Champ: Biblio : Biblio Citation */
$handler->display->display_options['fields']['citation']['id'] = 'citation';
$handler->display->display_options['fields']['citation']['table'] = 'biblio';
$handler->display->display_options['fields']['citation']['field'] = 'citation';
$handler->display->display_options['fields']['citation']['label'] = '';
$handler->display->display_options['fields']['citation']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['citation']['style_name'] = 'classic';
/* Champ: Contenu : Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Champ: Contenu : Titre */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
/* Critère de tri: Contenu : Date de publication */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filtre contextuel: Contenu : Nid */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'node';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['exception']['title'] = 'Tous / Toutes';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
/* Critère de filtrage: Contenu : Publié */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Critère de filtrage: Contenu : Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'biblio' => 'biblio',
);

/* Display: By AuthorID */
$handler = $view->new_display('system', 'By AuthorID', 'list_by_authorid');
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Champ: Contenu : Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Champ: Contenu : Titre */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Filtre contextuel: Biblio : Author ID */
$handler->display->display_options['arguments']['cid']['id'] = 'cid';
$handler->display->display_options['arguments']['cid']['table'] = 'biblio_contributor';
$handler->display->display_options['arguments']['cid']['field'] = 'cid';
$handler->display->display_options['arguments']['cid']['exception']['title'] = 'Tous / Toutes';
$handler->display->display_options['arguments']['cid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['cid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['cid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['cid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['cid']['break_phrase'] = TRUE;
$handler->display->display_options['path'] = 'view/personal-page/author-id';

/* Display: Liste Biblio */
$handler = $view->new_display('system', 'Liste Biblio', 'biblio_list');
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Champ: Biblio : Biblio Citation */
$handler->display->display_options['fields']['citation']['id'] = 'citation';
$handler->display->display_options['fields']['citation']['table'] = 'biblio';
$handler->display->display_options['fields']['citation']['field'] = 'citation';
$handler->display->display_options['fields']['citation']['label'] = '';
$handler->display->display_options['fields']['citation']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['citation']['style_name'] = 'classic';
$handler->display->display_options['path'] = 'view/ujf-personal-page/biblio';
$translatables['view_ujf_personal_page'] = array(
  t('Master'),
  t('plus'),
  t('Appliquer'),
  t('Réinitialiser'),
  t('Trier par'),
  t('Asc'),
  t('Desc'),
  t('Éléments par page'),
  t('- Tout -'),
  t('Décalage'),
  t('« premier'),
  t('‹ précédent'),
  t('suivant ›'),
  t('dernier »'),
  t('Titre'),
  t('Tous / Toutes'),
  t('By AuthorID'),
  t('Liste Biblio'),
);


  // Add view to list of views to provide.
  $views [$view->name] = $view;

  // At the end, return array of default views.
  return $views;
}