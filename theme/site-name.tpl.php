<?php
/**
 * @file site-name template
 */
?>

<div class="footer-site-name">
  <?php if (variable_get('site_name', "")): ?>
  <h1 id="site-name">
    <span><?php print variable_get('site_name', ""); ?></span>
  </h1>
  <?php endif; ?>
</div>
