
let progress_bar = $("#progress-bar");

function Drive(id) {
    let form = "{\"direction\" : \"" + id + "\", \"session\" : \"webapp\"}";

    $.get("/status", function (data) {
        let obj_status = JSON.parse(data);

        if (connected === true) {
            $.post("/control",
                form,
                function (data) {
                    console.log(data);
                }, "text").fail(function (jqXHR, textStatus, errorThrown) {
                alert("ERROR: NO CONNECTION");
            });
        }
    });
}

function Cmd(id) {
    let form = "{\"pre-commands\" : \"" + id + "\", \"session\" : \"webapp\"}";

    $.get("/status", function (data) {
        let obj_status = JSON.parse(data);

        if (connected === true) {
            $.post("/control",
                form,
                function (data) {
                    console.log(data);
                }, "text").fail(function (jqXHR, textStatus, errorThrown) {
                alert("ERROR: NO CONNECTION");
            });
        }
    });
}

function Stop() {
    let form = "{\"direction\" : \"" + "stop" + "\", \"session\" : \"webapp\"}";

    $.get("/status", function (data) {
        let obj_status = JSON.parse(data);

        if (connected === true) {
            $.post("/control",
                form,
                function (data) {
                    console.log(data);
                }, "text").fail(function (jqXHR, textStatus, errorThrown) {
                alert("ERROR: NO CONNECTION");
            });
        }
    });
}

function manualTimer() {
    $.get("/status", function (data) {

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
        if(obj_status.status === "busy"){
            connected = false;
            $('#message').show();
            $("#manual_panel").attr('class', 'panel panel-default');
            $("#autonomous_panel").attr('class', 'panel panel-default');
        }
    });
}

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