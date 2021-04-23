/*
 * ESP32 Blink
 * 
 * Built-in LED is connected to GPIO2
 */
#define LED_BUILTIN 2

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("On");
  digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(10000);                    // wait ten seconds
  Serial.println("Off");
  digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);                     // wait one second
}
