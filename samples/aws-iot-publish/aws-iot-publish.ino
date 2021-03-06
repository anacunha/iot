#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include "secrets.h"

#define AWS_IOT_THING_NAME "ESP32"
#define AWS_IOT_PUBLISH_TOPIC "iot/publish-sample"

const char* ssid = "<SSID>";
const char* password = "<PASSWORD>";

WiFiClientSecure wifiClient;
MQTTClient mqttClient;

void setup() {
  Serial.begin(115200);
  connectWiFi();
  connectAWS();
}

void loop() {
  mqttClient.loop();
  mqttClient.publish(AWS_IOT_PUBLISH_TOPIC, "{\"message\": \"Hello from ESP32!\"}");
  delay(1000);
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
