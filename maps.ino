#include <TinyGPS++.h> // library for GPS module
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include "DHT.h"
#define DHTPin D3
#define DHTTYPE DHT11

TinyGPSPlus gps;  // The TinyGPS++ object
SoftwareSerial ss(4, 5); // The serial connection to the GPS device

const char* ssid = "OnePlus Nord"; //ssid of your wifi
const char* password = "nimminikki"; //password of your wifi

const int forward = 14;
const int right = 12;


float latitude , longitude;
String lat_str , lng_str;
int x = 0;

ESP8266WebServer webServer(80);

DHT dht(DHTPin, DHTTYPE);

static char celsiusTemp[7];
static char humidityTemp[7];
void setup()
{
  Serial.begin(115200);
 
  ss.begin(9600);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password); //connecting to wifi
  while (WiFi.status() != WL_CONNECTED)// while wifi not connected
  {
    delay(500);
    Serial.print("."); //print "...."
  }
  Serial.println("");
  Serial.println("WiFi connected");
   
  pinMode(forward,OUTPUT);

  pinMode(right,OUTPUT);


  webServer.on("/", [](){
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    dtostrf(h, 6, 2, humidityTemp);
    float hic = dht.computeHeatIndex(t, h, false);
    dtostrf(hic, 6, 2, celsiusTemp);
    StaticJsonDocument<200> jsonDoc;
    jsonDoc["latitude"] = lat_str;
    jsonDoc["longitude"] = lng_str;
    jsonDoc["humidity"] = humidityTemp;
    jsonDoc["temperature"] = celsiusTemp;
    String jsonString;
    serializeJson(jsonDoc, jsonString);
    webServer.sendHeader("Access-Control-Allow-Origin", "*");
    webServer.send(200, "application/json", jsonString);
  });

  webServer.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());  // Print the IP address
}


void loop()
{
  while (ss.available() > 0) //while data is available
    if (gps.encode(ss.read())) //read gps data
    {
      if (gps.location.isValid()) //check whether gps location is valid
      {
        latitude = gps.location.lat();
        lat_str = String(latitude , 6); // latitude location is stored in a string
        longitude = gps.location.lng();
        lng_str = String(longitude , 6); //longitude location is stored in a string
      }   
    }
    
  WiFiClient client;
HTTPClient http;
http.begin(client, "http://192.168.24.33:3000/data");
int httpCode = http.GET();

if (httpCode>0) {
  String payload = http.getString();
   StaticJsonDocument<200> jsonDoc;
  DeserializationError error = deserializeJson(jsonDoc, payload);
    x = jsonDoc["x"].as<int>();
      Serial.print("x value from JSON: ");
      Serial.println(x);
      if(x==1)
      {digitalWrite(forward,HIGH);
      digitalWrite(right,LOW);
      }

      else if(x==2)
      {digitalWrite(forward,HIGH);
      digitalWrite(right,HIGH);
      }

      else if(x==3)
      {digitalWrite(forward,LOW);
      digitalWrite(right,HIGH);
      }
      
      else if(x==4)
      {digitalWrite(forward,LOW);
      digitalWrite(right,LOW);
      }
}
else {
  Serial.println(httpCode);
   Serial.println(http.errorToString(httpCode).c_str());
}
  webServer.handleClient();
  delay(1000);
}