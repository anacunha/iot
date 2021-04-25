#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include "secrets.h"

#define AWS_IOT_THING_NAME "ESP32"
#define AWS_IOT_SUBSCRIBE_TOPIC "iot/subscribe-sample"

const char* ssid = "<SSID>";
const char* password = "<PASSWORD>";

WiFiClientSecure wifiClient;
MQTTClient mqttClient;

void setup() {
  Serial.begin(115200);
  connectWiFi();
  connectAWS();
  subscribe();
}

void loop() {
  mqttClient.loop();
  delay(1000);
}

void subscribe() {
  mqttClient.onMessage(messageHandler);
  mqttClient.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);
}

void messageHandler(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " " + payload);
}

void connectAWS() {
  // Configure WiFiClientSecure to use AWS certificates
  wifiClient.setCACert(AWS_CERT_CA);
  wifiClient.setCertificate(AWS_CERT_CRT);
  wifiClient.setPrivateKey(AWS_CERT_PRIVATE);
  
  // Connect to MQTT broker to the AWS endpoint
  mqttClient.begin(AWS_IOT_ENDPOINT, 8883, wifiClient);

  Serial.println("Connecting to AWS IoT");

  while (!mqttClient.connect(AWS_IOT_THING_NAME)) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("AWS IoT Connected!");
}

void connectWiFi() {
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
}
