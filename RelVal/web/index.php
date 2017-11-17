<?php

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);

include('header.html');

if (isset($_GET['d'])) {

  $directory = $_GET['d'];
  $dirs = scandir($directory, 1);
  // Remove . and ..
  array_pop($dirs);
  array_pop($dirs);
  foreach (array_reverse($dirs) as $dir) {
    echo '<div style="clear:both;" onclick=reveal("' . $dir . '")>' . "\n";
    echo $dir . "\n";
    echo '<div id="' . $dir . '" style="display:none;" onclick=reveal(this)>' . "\n";
    $plots = scandir($directory . '/' . $dir);
    foreach ($plots as $plot) {
      $file_parts = pathinfo($plot);
      if ($file_parts['extension'] == 'pdf') {
        $base = $directory . '/' . $dir . '/' . $file_parts['filename'];
        echo '<span class="plot" style="float:left; width:25%;">';
        echo '<p>' . $file_parts['filename'] . '</p>';
        echo '<a href="' . $base . '.pdf"> <img src="' . $base . '.png" width="100%"></a>';
        echo '</span>' . "\n";
      }
    }
    echo '</div>' . "\n";
    echo '</div>' . "\n";
  }

} else {

  $dirs = array_filter(scandir('.', 1), 'is_dir');
  // Remove . and ..
  array_pop($dirs);
  array_pop($dirs);
  foreach ($dirs as $dir)
    echo '<a href="?d=' . $dir . '">' . $dir . '</a><br>' . "\n";

}

include('footer.html');

?>
