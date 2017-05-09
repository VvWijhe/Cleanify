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

function Connect(){
    let form = "{\"direction\" : \"" + "stop" + "\", \"session\" : \"webapp\"}";

    $.get("/status", function (data) {
        let obj_status = JSON.parse(data);

        if(obj_status.status !== "ava"){
            $.post("/control",
                form,
                function (data) {
                    console.log(data);
                }, "text").fail(function (jqXHR, textStatus, errorThrown) {
                alert("ERROR: NO CONNECTION");
            });}
        else{
            alert("ERROR: Already connected");
        }
    });
}

function Disconnect(){
    let form = "{\"exit\" : \"true\"}";

    $.post("/control",
        form,
        function (data) {
            console.log(data);
        }, "text").fail(function (jqXHR, textStatus, errorThrown) {
        alert("ERROR: NO CONNECTION");
    });


    $('#message').show();
    $("#manual_panel").attr('class', 'panel panel-default');
    $("#autonomous_panel").attr('class', 'panel panel-default');
}


function drive() {
    let form = "{\"direction\" : \"" + this.id + "\", \"session\" : \"webapp\"}";

    $.get("/status", function (data) {
        let obj_status = JSON.parse(data);

        if(obj_status.){
            $.post("/control",
                form,
                function (data) {
                    console.log(data);
                }, "text").fail(function (jqXHR, textStatus, errorThrown) {
                alert("ERROR: NO CONNECTION");
            });}
    });
}
