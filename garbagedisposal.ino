/*
 * Garbage Disposal push button; software for ATTiny Microcontroller
 * =================================================================
 * 
 * Copyright (c) 2018 Markus Gutschke
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define DEBOUNCE    100
#define PUSHANDHOLD 500
#define MAXRUNTIME   30
#define COOLOFF       2

#define LED           0
#define RELAY         1
#define BUTTON        2

static unsigned int  sm;
static unsigned int  seconds = 1;
static unsigned int  on = 0;
static unsigned int  tm = 0;
static unsigned char relayState = 0;
static unsigned char momentary = 0;
static unsigned char buttonState = 0;

void setup() {
  pinMode(LED,    INPUT);
  pinMode(RELAY,  OUTPUT);
  pinMode(BUTTON, INPUT);
  delay(COOLOFF * 1000);
  sm = millis() | 1;
}

void loop() {
  // Keep track of time since last button status change and seconds
  // since the relay has been turned on. Avoid integer overflows on
  // our tiny device.
  // Make sure that neither milli-seconds nor seconds on-time ever
  // become zero, as we are using this value as an indicator value.
  unsigned int m = millis() | 1;
  while (m - sm >= 1000) {
    if (!++seconds) {
      seconds = 1;
    }
    sm += 1000;
  }
  unsigned char b = digitalRead(BUTTON);
  if (b != buttonState) {
    // Detected change in button state
    buttonState = b;
    // Debounce, and tell momentary from latching button push
    if ((!tm && !momentary) || m - tm > DEBOUNCE) {
      if (!relayState) {
        // Relay is off. Turn it on, when button is pressed.
        if (buttonState) {
          digitalWrite(RELAY, HIGH);
          digitalWrite(LED, LOW);
          pinMode(LED, OUTPUT);
          relayState = 1;
          on = seconds;
        }
      } else {
        // Relay is on. Turn if off, when momentary button is released.
        // Also, turn it off, when latching button is pressed.
        if (momentary == !buttonState) {
          goto turnOff;
        }
      }
    }
    tm = m;
  }
  if (tm && m - tm > PUSHANDHOLD) {
    // Promote latching button to momentary button, if it is held down
    // for an extended amount of time.
    momentary = buttonState;
    tm = 0;
  }
  if (on && seconds - on >= MAXRUNTIME) {
    // Safety first! Don't let the relay run for unlimited time.
   turnOff:
    // Don't allow the motor to turn off right after having been turned on.
    if (on && seconds - on < COOLOFF) {
      delay((COOLOFF - (seconds - on)) * 1000);
    }
    digitalWrite(RELAY, LOW);
    pinMode(LED, INPUT);
    // Don't allow motor to turn on again for a couple of seconds. This
    // prevents users from rapidly turning the motor on and off in quick
    // succession.
    if (relayState) {
      delay(COOLOFF * 1000);
    }
    while (digitalRead(BUTTON)) { }
    buttonState = momentary = relayState = on = 0;
    tm = millis() | 1;
  }
}
