/**
 * @author Dustin Currie
 */

Drupal.behaviors.uncaptchalous = function () {
  $('#edit-uncaptchalous-js-val').attr('value', parseInt($('#edit-uncaptchalous-js-param1').val()) + parseInt($('#edit-uncaptchalous-js-param2').val()));
};
