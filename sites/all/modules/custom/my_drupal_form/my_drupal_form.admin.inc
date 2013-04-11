<?php
/**
*
*/
function my_drupal_form_admin_form($form, &$form_state) {
  dpm($form_state, '$form_state');

  $variable_persistante = variable_get('my_drupal_form_configuration', 'Variable persistante');
  $form['my_drupal_form'] = array(
    '#type' => 'textfield',
    '#title' => 'Variable persistante',
    '#default_value' => $variable_persistante,
    '#size' => 100,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Mettre à jour',
    '#submit' => array('my_drupal_form_admin_submit'),
    );

  return $form;
}


function my_drupal_form_admin_submit($form, &$form_state) {
  $variable_persistante = variable_get('my_drupal_form_configuration', NULL);
  $valeur_transmise = $form_state['values']['my_drupal_form'];

  if($variable_persistante != $valeur_transmise) {
    variable_set('my_drupal_form_configuration', $valeur_transmise);
    drupal_set_message('Variable mise à jour : "' . $variable_persistante . '" par "' . $valeur_transmise . '".');
  }
  else {
    drupal_set_message('La variable persistante est inchangée.');
  }

}
