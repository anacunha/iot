const int LED_PIN = 18;    // the number of the LED pin
const int BUTTON_PIN = 19; // the number of the pushbuton pin

int buttonState = 0;      // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(LED_PIN, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(BUTTON_PIN);

  // Pull Down
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(LED_PIN, HIGH);
  } else {
    // turn LED off:
    digitalWrite(LED_PIN, LOW);
  }
}
