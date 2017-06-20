/**
 * Created by victor on 11.05.17.
 */

let timerVar;
let connected = false;
let progress_bar = $("#progress-bar");
let wheels_value;
let brushes_value;


//connect button is pressed
function Connect() {
    let form = "{\"direction\" : \"" + "stop" + "\", \"session\" : \"webapp\"}";

    //retrieves status from the server
    $.get("/status", function (data) {
            let obj_status = JSON.parse(data);

            //if the site is available
            if (obj_status.status === "available") {
                timerVar = setInterval(timerControl, 500);
                connected = true;
                $.post("/control",
                    form,
                    function (data) {
                        console.log(data);
                    }, "text").fail(function (jqXHR, textStatus, errorThrown) {
                    alert("ERROR: NO CONNECTION");
                });
                $("#manual_panel").attr('class', 'panel panel-success');
                $("#autonomous_panel").attr('class', 'panel panel-success')
            }
            // if the server is busy and the site is not connected
            else if (obj_status.status === "busy" && connected === false) {
                $("#occupied").show();
                $("#manual_panel").attr('class', 'panel panel-danger');
                $("#autonomous_panel").attr('class', 'panel panel-danger')
            }
        }
    );
}

function Disconnect() {
    let form = "{\"exit\" : \"" + "true" + "\", \"session\" : \"webapp\"}";

    //retrieves status from the server
    $.get("/status", function (data) {
            let obj_status = JSON.parse(data);

            //if the site is available
            if (connected === true) {
                $.post("/control",
                    form,
                    function (data) {
                        console.log(data);
                    }, "text").fail(function (jqXHR, textStatus, errorThrown) {
                    alert("ERROR: NO CONNECTION");
                });
                timerVar = setInterval(timerControl, 0);
                connected = false;
                $("#manual_panel").attr('class', 'panel panel-default');
                $("#autonomous_panel").attr('class', 'panel panel-default')
            }
        }
    );
}


function Drive(id) {
    let form = "{\"direction\" : \"" + id + "\", \"session\" : \"webapp\", \"wheel_speed\" : " + wheels_value + ", \"brush_speed\" : " + brushes_value + "}";

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

function timerControl() {
    $.get("/status", function (data) {

        let obj_status = JSON.parse(data);
        progress_bar.css("width", ((obj_status.battery /3000)*100) + '%');
        document.getElementById("progress_number").textContent = ((((obj_status.battery /3000)*100).tofixed(2)) + '%');
        progress_bar.attr('class', 'progress-bar progress-bar-striped active');
        if (obj_status.battery <= 750) {
            progress_bar.attr('class', 'progress-bar progress-bar-striped active progress-bar-warning');
            if (obj_status.battery <= 300) {
                progress_bar.attr('class', 'progress-bar progress-bar-striped active progress-bar-danger');
            }
        }
    });
}

function Cmd(id){
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

$('#slider_motor').slider({
    tooltip_position: 'bottom',
    formatter: function (value) {
        wheels_value = value;
        return `Motors are on : ${Number((value * 100).toFixed(2))}%`;

    }
});
$('#slider_brush').slider({
    tooltip_position: 'bottom',
    formatter: function (value) {
        brushes_value = (value * 127);
        return 'Brushes are on : ' + Number((value * 100).toFixed(2)) + '%';
    }
});