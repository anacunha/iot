#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include "secrets.h"

#define AWS_IOT_THING_NAME "ESP32"

const char* ssid = "<SSID>";
const char* password = "<PASSWORD>";

WiFiClientSecure wifiClient = WiFiClientSecure();
MQTTClient mqttClient = MQTTClient();

void setup() {
  Serial.begin(115200);
  connectWiFi();
  connectAWS();
}

void loop() {
  // put your main code here, to run repeatedly:
}

void connectAWS() {

  // Configure WiFiClientSecure to use AWS certificates
  wifiClient.setCACert(AWS_CERT_CA);
  wifiClient.setCertificate(AWS_CERT_CRT);
  wifiClient.setPrivateKey(AWS_CERT_PRIVATE);

  // Connect to the MQTT broker on the AWS endpoint
  mqttClient.begin(AWS_IOT_ENDPOINT, 8883, wifiClient);

  Serial.println("Connecting to AWS IoT");

  while (!mqttClient.connect(AWS_IOT_THING_NAME)) {
    Serial.print(".");
    delay(250);
  }

  if (!mqttClient.connected()) {
    Serial.println("AWS IoT Timeout!");
    return;
  }

  Serial.println("AWS IoT Connected!");
}

void connectWiFi() {
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}
