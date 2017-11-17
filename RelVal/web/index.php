<?php

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);

include('header.html');

function has_no_dot($a) {
  return strpos($a, '.') === FALSE;
}

if (isset($_GET['d'])) {

  $directory = $_GET['d'];
  $dirs = array_filter(scandir($directory, 1), 'has_no_dot');

  $meta_file = $directory . '/metadata.txt';
  if (file_exists($meta_file)) {
    echo '<div class="metadata">' . "\n";
    echo nl2br(file_get_contents($meta_file));
    echo '</div>' . "\n";
  }

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

  $dirs = array_filter(scandir('.', 1), 'has_no_dot');
  foreach ($dirs as $dir)
    printf('<a href="?d=%s"><header><h3>%s</h3></header></a><br>' . "\n", $dir, $dir);

}

include('footer.html');

?>
