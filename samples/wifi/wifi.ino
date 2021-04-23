#include <WiFi.h>
const char* ssid = "<SSID>";
const char* password = "<PASSWORD>";

void setup() {
  Serial.begin(115200);
  connectWiFi();
}

void loop() {
  // put your main code here, to run repeatedly:
}

void connectWiFi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Successfully connected to ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}
