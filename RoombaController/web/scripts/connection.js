/**
 * Created by victor on 11.05.17.
 */
let manualtimerVar;
let autotimerVar;
let connected = false;

function Connect() {
    let form = "{\"direction\" : \"" + "stop" + "\", \"session\" : \"webapp\"}";

    $.get("/status", function (data) {
        let obj_status = JSON.parse(data);

        if (obj_status.status === "available") {
            manualtimerVar = setInterval(manualTimer, 500);
            autotimerVar = setInterval(manualTimer, 600)
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

function Disconnect() {
    let form = "{\"exit\" : \"true\"}";
    connected = false;
    clearInterval(manualtimerVar);
    clearInterval(autotimerVar);
    $.post("/control",
        form,
        function (data) {
            console.log(data);
        }, "text").fail(function (jqXHR, textStatus, errorThrown) {
        alert("ERROR: NO CONNECTION");
    });
    progress_bar.css("width", "0%");
    document.getElementById("progress_number").textContent = ("");
    $('#message').show();
    $("#manual_panel").attr('class', 'panel panel-default');
    $("#autonomous_panel").attr('class', 'panel panel-default');
}
