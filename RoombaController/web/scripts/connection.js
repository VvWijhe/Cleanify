/**
 * Created by victor on 11.05.17.
 */

var timerVar;
var connected = false;

function Connect() {
    let form = "{\"direction\" : \"" + "stop" + "\", \"session\" : \"webapp\"}";

    $.get("/status", function (data) {
        let obj_status = JSON.parse(data);

        if (obj_status.status === "available") {
            //timerVar = setInterval(myTimer, 500);
            connected = true;
            $("#manual_panel").attr('class', 'panel panel-success');
            $("#autonomous_panel").attr('class', 'panel panel-success');
            $.post("/control",
                form,
                function (data) {
                    console.log(data);
                }, "text").fail(function (jqXHR, textStatus, errorThrown) {
                alert("ERROR: NO CONNECTION");
            });
        }
        else if (obj_status.status === "busy") {
            connected = false;
            $("#occupied").show();
            $("#manual_panel").attr('class', 'panel panel-danger');
            $("#autonomous_panel").attr('class', 'panel panel-danger')
        }
    });
}