/**
 * @author Dustin Currie
 */

Drupal.behaviors.uncaptchalous = {
  'attach': function(context, settings) {
    jQuery('[name='+Drupal.settings.uncaptchalous[0]+']').val(parseInt(jQuery('[name='+Drupal.settings.uncaptchalous[1]+']').val()) + parseInt(jQuery('[name='+Drupal.settings.uncaptchalous[2]+']').val()));
  }
};
