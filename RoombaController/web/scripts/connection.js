/**
 * Created by victor on 11.05.17.
 */

let varManual;
let varAuto;
let connected = false;


//connect button is pressed
function Connect() {
    let form = "{\"direction\" : \"" + "stop" + "\", \"session\" : \"webapp\"}";

    //retrieves status from the server
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
    );
}
//if the disconnect button is pressed
function Disconnect() {
    let form = "{\"exit\" : \"true\"}";
    if(connected === true) {
        connected = false;
        $.post("/control",
            form,
            function (data) {
                console.log(data);
            }, "text").fail(function (jqXHR, textStatus, errorThrown) {
            alert("ERROR: NO CONNECTION");
        });
        progress_bar.css("width", "0%");
        document.getElementById("progress_number").textContent = ("");
        //changes the panel collors to default
        $('#message').show();
        $("#manual_panel").attr('class', 'panel panel-default');
        $("#autonomous_panel").attr('class', 'panel panel-default');
    }
}