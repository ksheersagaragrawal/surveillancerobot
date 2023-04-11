function initMap() {
    var location = {lat: 0, lng: 0};
    var map = new google.maps.Map(document.getElementById('map'), {
        zoom: 10,
        center: location
    });
    var marker = new google.maps.Marker({
        position: location,
        map: map
    });
    
    function fetchcoordinates() {
        // Make a GET request to the server endpoint
        fetch('http://192.168.197.130/')
            .then(response => response.json())
            .then(data => {
                // Update the marker position and center the map on the new location
                location.lat = parseFloat(data.latitude);
                location.lng = parseFloat(data.longitude);

                marker.setPosition(location);
                map.setCenter(location);
                
                // Update the temperature and humidity data on the website
                document.getElementById('tem').textContent = data.temperature + ' °C';;
                document.getElementById('hum').textContent = data.humidity + ' %';
            })
            .catch(error => console.error(error));
    }
    
    fetchcoordinates(); 
    setInterval(fetchcoordinates, 10000);
}