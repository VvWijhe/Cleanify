/**
 * Created by victor on 04.05.17.
 */


$('#slider_motor').slider({
    tooltip_position: 'bottom',
    formatter: function (value) {
        $("#progress-bar").css("width", (value * 100) +'%');
        document.getElementById("progress_number").textContent=(Number((value * 100).toFixed(2))+'%');
        return 'Motors are on : ' + Number((value * 100).toFixed(2)) + '%';

    }
});
$('#slider_brush').slider({
    tooltip_position: 'bottom',
    formatter: function (value) {
        return 'Brushes are on : ' + Number((value * 100).toFixed(2)) + '%';
    }
});


// $(function () {
//     $("#progress-bar").css("width", "50%");
//
// });

function danger() {
    $("#battery-bar").attr('class', 'alert alert-danger');
    $("#manual_panel").attr('class', 'panel panel-danger')
}
function nodanger() {
    $("#battery-bar").attr('class', 'alert alert-success');
    $("#manual_panel").attr('class', 'panel panel-success')
}

function move(){

}
function stop(){
    
}



$(document).ready(function () {
    $(".dir").click(function () {
        var form = "{\"direction\" : \"" + this.id + "\", \"session\" : \"webapp\"}";

        $.post("/control",
            form,
            function (data) {
                console.log(data);
            }, "text").fail(function (jqXHR, textStatus, errorThrown) {
            alert("ERROR: NO CONNECTION");
        });
    });

    $("#EXIT").click(function () {
        var form = "{\"exit\" : \"true\"}";

        $.post("/control",
            form,
            function (data) {
                console.log(data);
            }, "text").fail(function (jqXHR, textStatus, errorThrown) {
            alert("ERROR: NO CONNECTION");
        });
    });
});
