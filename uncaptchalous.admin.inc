<?php
// $Id$

/**
 * @file
 *
 * Contains code related to customizeable admin settings
 *
 * @author Dustin Currie <dustinc@getlevelten.com>
 */

/**
 * Menu callback for admin/webform/settings.
 */

function uncaptchalous_settings() {
  $form = array();

  $form['uncaptchalous_javascript'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hidden JavaScript actions'),
    '#description' => t('Require Javascript to perform actions on hidden elements in forms for
                         forms to validate. If these actions are not performed, it is assumed
                         that the form was not submitted by a human user.  NOTE: This method requires javascript'),
    '#default_value' => variable_get('uncaptchalous_javascript', 1),
  );
  $form['honeypot'] = array(
    '#type' => 'fieldset',
    '#title' => t('Honeypot Field'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('Create a textfield that is not displayed in forms.  If this form is filled out
                        it is assumed to be filled by a spam bot and does not validate.'),
  );
  $form['honeypot']['uncaptchalous_honeypot_field'] = array(
    '#type' => 'checkbox',
    '#title' => t('Honeypot field'),
    '#description' => t('Enable Honeypot'),
    '#default_value' => variable_get('uncaptchalous_honeypot_field', 1),
  );
  $form['honeypot']['uncaptchalous_honeypot_field_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title for honeypot field'),
    '#description' => t('Change this value to throw off bots'),
    '#default_value' => variable_get('uncaptchalous_honeypot_field_title', 'url'),
  );

  $form['form_vis_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Form specific visibility settings'),
    '#collapsible' => TRUE,
  );
  $access = user_access('use PHP for block visibility');
  $options = array(t('Use on every form except the listed form ids.'), t('Show on only the listed form ids.'));
  $description = t("Enter one form id per line as form ids. The '*' character is a wildcard.");

  if ($access) {
    $options[] = t('Show if the following PHP code returns <code>TRUE</code> (PHP-mode, experts only).');
    $description .= ' '. t('If the PHP-mode is chosen, enter PHP code between %php. Note that executing incorrect PHP-code can break your Drupal site.', array('%php' => '<?php ?>'));
  }
  $form['form_vis_settings']['uncaptchalous_visibility'] = array(
    '#type' => 'radios',
    '#title' => t('Use un.captcha.lous on specific forms'),
    '#options' => $options,
    '#default_value' => variable_get('uncaptchalous_visibility', 1),
  );
  $form['form_vis_settings']['uncaptchalous_form_ids'] = array(
    '#type' => 'textarea',
    '#title' => t('Form Ids'),
    '#default_value' => variable_get('uncaptchalous_form_ids', ""),
    '#description' => $description,
  );
  return system_settings_form($form);
}
