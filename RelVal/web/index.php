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
    printf('<header onclick=reveal("%s")>' . "\n", $dir);
    printf('<h3>%s</h3>' . "\n", $dir);
    echo '</header>' . "\n";
    printf('<div style="display:none;" class="plots" id="%s">' . "\n", $dir);
    $plots = scandir($directory . '/' . $dir);
    foreach ($plots as $plot) {
      $file_parts = pathinfo($plot);
      if ($file_parts['extension'] == 'pdf' and substr($file_parts['filename'], -4) != '_log') {
        $base = $directory . '/' . $dir . '/' . $file_parts['filename'];
        $plot_id = $dir . '/' . $file_parts['filename'];
        echo '<span class="plot">';
        printf('<span class="plot_head">%s ' .
               '<span class="lin_indicator" id="%s_status-lin">linear</span>' .
               '<span style="display:none;" class="log_indicator" id="%s_status-log">log</span> <br> ' .
               '<button class="log_button" onclick=swap_log("%s")>toggle log plots</button>' .
               '</span>',
               $plot_id, $plot_id, $plot_id, $plot_id);
        printf('<span id="%s"><a href="%s.pdf" target="_blank"> <img src="%s.png" width="100%s"></a></span>',
               $plot_id, $base, $base, '%');
        printf('<span style="display:none;" id="%s_log"><a href="%s_log.pdf" target="_blank"> <img src="%s_log.png" width="100%s"></a></span>',
               $plot_id, $base, $base, '%');
         echo '</span>' . "\n";
      }
    }
    echo '</div>' . "\n";
  }

} else {

  $dirs = array_filter(scandir('.', 1), 'is_dir');
  // Remove . and ..
  array_pop($dirs);
  array_pop($dirs);
  foreach ($dirs as $dir)
    printf('<a href="?d=%s"><header><h3>%s</h3></header></a><br>' . "\n", $dir, $dir);

}

include('footer.html');

?>
