/**
 * Created by victor on 04.05.17.
 */

var myVar = setInterval(myTimer, 100);


$('#slider_motor').slider({
    tooltip_position: 'bottom',
    formatter: function (value) {
        return `Motors are on : ${Number((value * 100).toFixed(2))}%`;

    }
});
$('#slider_brush').slider({
    tooltip_position: 'bottom',
    formatter: function (value) {
        return 'Brushes are on : ' + Number((value * 100).toFixed(2)) + '%';
    }
});



function myTimer() {
    $.get("/status", function (data) {
        let progress_bar = $("#progress-bar");
        let obj_status = JSON.parse(data);
        progress_bar.css("width", (obj_status.battery) + '%');
        document.getElementById("progress_number").textContent = ( obj_status.battery + '%');
        progress_bar.attr('class', 'progress-bar progress-bar-striped active');
        if (obj_status.battery <= 25) {
            progress_bar.attr('class', 'progress-bar progress-bar-striped active progress-bar-warning');
            if (obj_status.battery <= 10) {
                progress_bar.attr('class', 'progress-bar progress-bar-striped active progress-bar-danger');
            }
        }

    });
}




$(document).ready(function () {
    $(".dir").click(function () {
        let form = "{\"direction\" : \"" + this.id + "\", \"session\" : \"webapp\"}"

        $.post("/control",
            form,
            function (data) {
                console.log(data);
                let obj_control = JSON.parse(data);
                if (obj_control.message === "busy") {
                    $("#occupied").show();
                } else {
                    $("#occupied").hide();
                }

            }, "text").fail(function (jqXHR, textStatus, errorThrown) {
            alert("ERROR: NO CONNECTION");
        });
        $("#manual_panel").attr('class', 'panel panel-success');
        $("#autonomous_panel").attr('class', 'panel panel-success')
        $('#message').toggle();

    });

    $("#EXIT").click(function () {
        let form = "{\"exit\" : \"true\"}";

        $.post("/control",
            form,
            function (data) {
                console.log(data);
            }, "text").fail(function (jqXHR, textStatus, errorThrown) {
            alert("ERROR: NO CONNECTION");
        });


        $('#message').toggle();
        $("#manual_panel").attr('class', 'panel panel-default');
        $("#autonomous_panel").attr('class', 'panel panel-default');

    });
});

function myMap() {
    let Cleanify = {lat: 51.9889801, lng: 5.949402};
    let mapCanvas = document.getElementById("map");
    let mapOptions = {
        center: new google.maps.LatLng(Cleanify), zoom: 16,
        scrollwheel: false
    };
    let map = new google.maps.Map(mapCanvas, mapOptions);
    let marker = new google.maps.Marker({
        position: Cleanify,
        map: map
    });
}