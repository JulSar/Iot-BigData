#ifdef ARDUINO_ARCH_SAMD
#include <WiFi101.h>
#elif defined ARDUINO_ARCH_ESP8266
#include <ESP8266WiFi.h>
#elif defined ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#error Wrong platform
#endif
#include <WifiLocation.h>
#include <Adafruit_NeoPixel.h>
#include <MQTT.h>

void myDataCb(String& topic, String& data);
void myPublishedCb();
void myDisconnectedCb();
void myConnectedCb();

#define CLIENT_ID "juju"
#define TOPIC "topic/wifi"

const char* ssid = "HUAWEI_Honor 8_9FC0";
const char* passwd = "sou33lerlathonor";
const char* mqttServer = "51.15.208.245";
const int mqttPort = 1883;
String mqtttopic = "topic/wifi";
const char* message = "hello";

// create MQTT
MQTT myMqtt(CLIENT_ID, mqttServer, mqttPort);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(8, D6, NEO_GRB + NEO_KHZ800);

const char* googleApiKey = "AIzaSyAozX6EThsQBjP4BKVX9wFWC_0lI-sMcZk";

WifiLocation location(googleApiKey);

void setup() {
  pixels.begin();
  pixels.show();
  delay(100);
  Serial.begin(115200);
  // Connect to WPA/WPA2 network
#ifdef ARDUINO_ARCH_ESP32
  WiFi.mode(WIFI_MODE_STA);
#endif
#ifdef ARDUINO_ARCH_ESP8266
  WiFi.mode(WIFI_STA);
#endif
  WiFi.begin(ssid, passwd);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // wait 5 seconds for connection:
    Serial.print("Status = ");
    Serial.println(WiFi.status());
    delay(500);
  }

  Serial.println("Connected to WIFI");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Connecting to MQTT server");

  // setup callbacks
  myMqtt.onConnected(myConnectedCb);
  myMqtt.onDisconnected(myDisconnectedCb);
  myMqtt.onPublished(myPublishedCb);
  myMqtt.onData(myDataCb);

  Serial.println("connect mqtt...");
  myMqtt.connect();

  Serial.println("subscribe to topic...");
  myMqtt.subscribe(TOPIC);
  delay(10);
}

void loop() {

  location_t loc = location.getGeoFromWiFi();
  String data = location.getSurroundingWiFiJson();
  String score = parsedata(data);
  Serial.println("Location request data");
  Serial.println("Latitude    : " + String(loc.lat, 7));
  Serial.println("Longitude   : " + String(loc.lon, 7));
  Serial.println("Best signal : " + score);

  String res =  String(loc.lat, 7) + "," +  String(loc.lon, 7) + "," + score;
  set_pixels(score);
  myMqtt.publish(mqtttopic, res);
  delay(1000);
}

void set_pixels(String score) {
  int limit = 0;
  if (score.toInt() <= 100) {
    limit = 1;
  }
  if (score.toInt() <= 80) {
    limit = 2;
  }
  if (score.toInt() <= 70) {
    limit = 3;
  }
  if (score.toInt() <= 60) {
    limit = 4;
  }
  if (score.toInt() <= 50) {
    limit = 5;
  }
  if (score.toInt() <= 40) {
    limit = 6;
  }
  if (score.toInt() <= 30) {
    limit = 7;
  }
  if (score.toInt() <= 20) {
    limit = 8;
  }
  for (int i = 0; i < limit; i++) {
    if (i == 0 || i == 1) {
      pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    }
    if (i == 2 || i == 3 || i == 4 ) {
      pixels.setPixelColor(i, pixels.Color(150, 150, 0));
    }
    if (i == 5 || i == 6 || i == 7) {
      pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    }
    pixels.setBrightness(30);
    pixels.show();
  }
}

String parsedata(String data)
{
  int range = 53;
  int jump = 69;
  int tmp_val = 100;

  //jump at the first value
  String current = data.substring(range);
  //keep the value in memory
  int val = current.substring(1, 3).toInt();
  while (current.length() > jump) {
    if ( current.charAt(0) == '-')
    {
      tmp_val = current.substring(1, 3).toInt();
      if (tmp_val < val) {
        val = tmp_val;
      }
    }
    current = current.substring(1);
  }
  return String(val);
}

void myConnectedCb()
{
  Serial.println("connected to MQTT server");
}

void myDisconnectedCb()
{
  Serial.println("disconnected. try to reconnect...");
  delay(500);
  myMqtt.connect();
}

void myPublishedCb()
{
  Serial.println("published.");
}

void myDataCb(String& topic, String& data)
{
  Serial.print(topic);
  Serial.print(": ");
  Serial.println(data);
}
