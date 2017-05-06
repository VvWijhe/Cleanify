/**
 * Created by victor on 04.05.17.
 */


$('#slider_motor').slider({
    tooltip_position: 'bottom',
    formatter: function (value) {
        $("#progress-bar").css("width", (value * 100) +'%');
        $("#progress-bar").attr('class', 'progress-bar progress-bar-striped active');
        if(value <= 0.25){
            $("#progress-bar").attr('class', 'progress-bar progress-bar-striped active progress-bar-warning');
            if(value <= 0.1){
                $("#progress-bar").attr('class', 'progress-bar progress-bar-striped active progress-bar-danger');
            }
        }

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

    $("#CONNECT").click(function(){
        // $("#message").attr('class', 'alert alert-success');
        $("#manual_panel").attr('class', 'panel panel-success');
        $("#autonomous_panel").attr('class', 'panel panel-success')
        $('#message').toggle();

    });

    $("#EXIT").click(function(){
        $('#message').toggle();
        $("#manual_panel").attr('class', 'panel panel-default');
        $("#autonomous_panel").attr('class', 'panel panel-default')
    });


});

function myMap() {
    var Cleanify = {lat: 51.9873201, lng: 5.9511133};
    var mapCanvas = document.getElementById("map");
    var mapOptions = {
        center: new google.maps.LatLng(Cleanify), zoom: 18,
        scrollwheel: false
    };
    var map = new google.maps.Map(mapCanvas, mapOptions);
    var marker = new google.maps.Marker({
        position: Cleanify,
        map: map
    });
}