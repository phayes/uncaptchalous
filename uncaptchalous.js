/**
 * @author Dustin Currie
 */

Drupal.behaviors.uncaptchalous = {
  'attach': function(context, settings) {
    var solution = parseInt(jQuery('[name=uncaptchalous_js_param1]').val()) + parseInt(jQuery('[name=uncaptchalous_js_param2]').val());
    jQuery('[name=uncaptchalous_js_val]').val(solution);
  }
};
