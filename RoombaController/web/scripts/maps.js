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