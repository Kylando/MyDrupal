
<?php

  /**
   * Implements a hook preprocess office node
   */

  function mydrupal_preprocess_node(&$variables) {
    if($variables['type'] == 'office') {

      /**ADDRESS FIELD - LOCALITY**/
      $locality = $variables['field_venue_address'][0]['locality'];



      /**ADDRESS FIELD - COUNTRY**/
      //Get the iso format of the country selected
      $country_field_iso = $variables['content']['field_venue_address']['#items'][0]['country'];
      //Get the list of the countries iso format
      $country_iso_list = $variables['content']['field_venue_address'][0]['country']['#options'];



      //Get the country in full text format
      foreach ($country_iso_list as $country_iso => $value) {
        if($country_field_iso == $country_iso) {
          $country = $value;
        }
      }

      $variables['title_bis'] =  "Wunderkraut " . $country . " (" . $locality . ") ";
   }
  }



