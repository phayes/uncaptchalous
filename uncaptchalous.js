<?php

/**
 * Menu callback for admin/webform/settings.
 */

function uncaptchalous_settings() {
  $form = array();

  $form['uncaptchalous_javascript'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hidden Javascript actions'),
 