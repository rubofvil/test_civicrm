<?php

/**
 * @file
 * TODO: Enter file description here.
 */

/**
 * Form builder.
 */
function test_civicrm_settings_form($form, &$form_state) {
  $form['test_civicrm_variable_foo'] = array(
    '#type' => 'textfield',
    '#title' => t('Foo'),
    '#default_value' => variable_get('test_civicrm_variable_foo', 42),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
