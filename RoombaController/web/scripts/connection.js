/**
 * Created by victor on 11.05.17.
 */

let varManual;
let varAuto;
let connected = false;

function Connect() {
    let form = "{\"direction\" : \"" + "stop" + "\", \"session\" : \"webapp\"}";

    $.get("/status", function (data) {
            let obj_status = JSON.parse(data);

            //if the site is available
            if (obj_status.status === "available") {
                varManual = setInterval(timerManual, 500);
                varAuto = setInterval(timerAuto, 500);
                connected = true;
                $.post("/control",
                    form,
                    function (data) {
                        console.log(data);
                    }, "text").fail(function (jqXHR, textStatus, errorThrown) {
                    alert("ERROR: NO CONNECTION");
                });
            }
            // if the server is busy and the site is not connected
            else if (obj_status.status === "busy" && connected === false) {
                $("#occupied").show();
                $("#manual_panel").attr('class', 'panel panel-danger');
                $("#autonomous_panel").attr('class', 'panel panel-danger')
            }
        }
    )
    ;
}