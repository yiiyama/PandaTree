<?php

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);

include('header.html');

function has_no_dot($a) {
  return strpos($a, '.') === FALSE;
}

function list_directory($directory) {
  $directory = ltrim($directory, '/');
  if (!file_exists($directory) or strpos($directory, '..') !== FALSE)
    $directory = '.';

  $objs = array_filter(scandir($directory), 'has_no_dot');

  $meta_file = $directory . '/metadata.txt';
  if (file_exists($meta_file)) {
    echo '<div class="metadata">' . "\n";
    echo nl2br(file_get_contents($meta_file));
    echo '</div>' . "\n";

    uasort($objs, 'put_common_in_front');

    foreach ($objs as $obj) {
      printf('<header onclick=reveal("%s")>' . "\n", $obj);
      printf('<h3>%s</h3>' . "\n", $obj);
      echo '</header>' . "\n";
      printf('<div style="display:none;" class="plots" id="%s">' . "\n", $obj);
      $plots = scandir($directory . '/' . $obj);
      foreach ($plots as $plot) {
        $file_parts = pathinfo($plot);
        if ($file_parts['extension'] == 'pdf' and substr($file_parts['filename'], -4) != '_log') {
          $base = $directory . '/' . $obj . '/' . $file_parts['filename'];
          $plot_id = $obj . '/' . $file_parts['filename'];
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

    foreach ($objs as $dir)
      printf('<a href="?d=%s"><header><h3>%s</h3></header></a><br>' . "\n", ltrim($directory . '/', './') . $dir, $dir);

  }
}

function put_common_in_front($a, $b) {
  if ($a == 'common')
    return -1;
  if ($b == 'common')
    return 1;
  return ($a < $b) ? -1 : 1;
}

$dirs = array_filter(scandir('.', 1), 'has_no_dot');

$directory = isset($_GET['d']) ? $_GET['d'] : '.';

list_directory($directory);

include('footer.html');

?>
