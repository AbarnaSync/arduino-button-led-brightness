#define LED 9      // PWM pin
#define BTN 2

int brightness = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(BTN) == LOW) {   // button pressed

    brightness = brightness + 51;  // step increase

    if (brightness > 255) {
      brightness = 0;              // reset
    }

    analogWrite(LED, brightness);  // PWM output

    delay(300);                    // debounce

    // button release wait
    while (digitalRead(BTN) == LOW);
  }
}

