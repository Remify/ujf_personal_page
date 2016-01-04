<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */


global $user;
$page_user = menu_get_object('user');
$is_same_user = false;

if ($page_user->uid == $user->uid) {
$is_same_user = true;
}

drupal_add_css(drupal_get_path('module', 'ujf_personal_page') . '/template/css/user-profile.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
if(	$user_profile['field_user_publier'][0]['#markup'] === 'Oui' ||
	$is_same_user ||
	user_access('administer users') &&
	$page_user->field_user_status['und'][0]['value'] === '0'):

	if($user_profile['field_user_publier'][0]['#markup'] === 'Non' && $is_same_user) {
		drupal_set_message('Votre profil n\'est pas visible.', 'warning');
	}
?>
<div class="profile"<?php print $attributes; ?>>
	<div class="user-profile-wrapper">
		<div class="user-profile-pic">
			<?php
			if(isset($page_user->picture)){
				print theme('image_style', array( 'path' =>  $page_user->picture->uri, 'style_name' => 'medium'));
			}
			//print render($user_profile['user_picture']); ?>
		</div>

		<div class="user-profile-info">
			<div class="user-profile-info-nom">
				<h3>
					<?php print $user_profile['field_user_prenom'][0]['#markup'] .'&nbsp;'. $user_profile['field_user_nom'][0]['#markup']; ?>
				</h3>
			</div>
			<div class="user-profile-info-sous-titre">
				<?php print render($user_profile['field_sous_titre']); ?>
			</div>
			<div class="user-profile-info-contact">
				<div class="user-profile-info-contact-mail"><?php print render($user_profile['field_user_mail']); ?></div>
				<div class="user-profile-info-contact-phone"><?php print render($user_profile['field_user_phone']); ?></div>
				<div class="user-profile-info-contact-bureau"><?php print render($user_profile['field_user_bureau']); ?></div>
				<div class="user-profile-info-contact-bureau"><?php print render($user_profile['field_user_batiment']); ?></div>
				<div class="user-profile-info-contact-website"><a href="<?php print $user_profile['field_user_website'][0]['#markup']; ?>" target="_blank"><?php print render($user_profile['field_user_libelle_website']); ?></a></div>
			</div>
			<div class="user-profile-info-equipe">
				<?php
					dpm($user_profile);
						print render($node_equipe['node']->field_equipe_lien);
					foreach($user_profile['field_user_equipe_reference']['#items'] as $node_equipe) {
						print '<a href="' . $node_equipe['node']->field_equipe_lien['und'][0]['url'] .'">' . $node_equipe['node']->field_equipe_lien['und'][0]['title'] . '</a>';
					}

				?>
			</div>
		</div>
		<div class="user-profile-biblio">
		<?php

			if($page_user->data['biblio_contributor_id'] > 0) {
		?>
		<h3>Mes Travaux</h3>
		<?php
			$publi_arr = array();
			foreach($user_profile['field_user_publi_une']['#items'] as $key => $value) {
			$id = $value['value'];
			array_push($publi_arr, $id);
			}

			$arg = implode(",", $publi_arr);


			$view = views_get_view('view_ujf_personal_page');
			$view->set_display('biblio_list');
			$view->set_arguments(array($arg));
			// change the amount of items to show
			$view->pre_execute();
			$view->execute();
			print $view->render();

			print '<div class="user-profile-biblio-link"><a href="/user/'.$page_user->uid.'/biblio">Toutes les publications</a></div>';
		}
		?>
		</div>
		<div class="user-profile-content">
			<?php print render($user_profile['field_user_body']); ?>
		</div>
	</div>
</div>
<?php

else:drupal_goto('403-acces-refuse');
endif;
?>
