/**
 * Created by victor on 04.05.17.
 */

$(document).ready(function () {
    $(".dir").click(function () {
        let form = "{\"direction\" : \"" + this.id + "\", \"session\" : \"webapp\"}";

        $.post("/control",
            form,
            function (data) {
                console.log(data);
                let obj_control = JSON.parse(data);
                if (obj_control.message === "busy") {
                    $("#occupied").show();
                    $("#manual_panel").attr('class', 'panel panel-danger');
                    $("#autonomous_panel").attr('class', 'panel panel-danger')
                } else {
                    $("#occupied").hide();
                    $("#manual_panel").attr('class', 'panel panel-success');
                    $("#autonomous_panel").attr('class', 'panel panel-success')
                }

            }, "text").fail(function (jqXHR, textStatus, errorThrown) {
            alert("ERROR: NO CONNECTION");
        });

        $('#message').show();

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

