function reveal(id) {

    var div = document.getElementById(id);
    if (div.style.display == "none")
        div.style.display = "inline";
    else
        div.style.display = "none";

}

function swap_log(id_base) {

    reveal(id_base);
    reveal(id_base + '_log');
    reveal(id_base + '_status-lin');
    reveal(id_base + '_status-log');

}
