function reveal(id) {

    var div = document.getElementById(id);
    if (div.style.display == "none")
        div.style.display = "inline";
    else
        div.style.display = "none";

    if (JSON.parse(div.innerHTML) || JSON.parse(null)) {
        var plots = JSON.parse(div.innerHTML).plots;
        div.innerHTML = '';
        plots.forEach(function (obj) {
                div.innerHTML += '<span class="plot' + obj.warn + '">' +
                    ('<span class="plot_head">%s <span class="lin_indicator" id="%s_status-lin">linear</span>' +
                     '<span style="display:none;" class="log_indicator" id="%s_status-log">log</span> <br> ' +
                     '<button class="log_button" onclick=swap_log("%s")>toggle log plots</button></span>').replace('%s', obj.id) +
                    '<span id="' + obj.id + '"><a href="' + obj.base + '.pdf" target="_blank"> <img src="' + obj.base +
                    '.png" width="100%"></a></span>' +
                    '<span style="display:none;" id="' + obj.id + '_log"><a href="' + obj.base + '_log.pdf" target="_blank"> <img src="' + obj.base +
                    '_log.png" width="100%"></a></span>' +
                    '</span>';
            });
    }
}

function swap_log(id_base) {

    reveal(id_base);
    reveal(id_base + '_log');
    reveal(id_base + '_status-lin');
    reveal(id_base + '_status-log');

}
