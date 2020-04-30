#include "Arduino.h"
#include "PushButton.h"

PushButton::PushButton(int pinNumber, unsigned long debounceDelay, buttonPressCallback func)
{
  pin = pinNumber;
  dbDelay = debounceDelay;
  lastDbState = digitalRead(pin);
  value = lastDbState;
  lastDbTime = millis();
  callback = func;
  buttonState = LOW;
  debounceTime = 0;
}

void PushButton::check()
{
	isPressed();
}

boolean PushButton::isPressed()
{
	// Check to see if the button has changed state
	if (digitalRead(pin) != buttonState) {
		// Remember the new state
		buttonState = digitalRead(pin);
		// If the new state is LOW ...
		if (buttonState == LOW) {
			// ... then record the time stamp
			debounceTime = millis();
		} else {
			// ... otherwise set the time stamp to 0 for "don't care".
			debounceTime = 0;
		}
	}

	// If the time stamp is more than 0 and the difference between now and
	// then is greater than 10ms ...
	if (debounceTime > 0 && (millis() - debounceTime > 10)) {
		// ... set the time stamp to 0 to say we have finished debouncing
		debounceTime = 0;
		callback();
		return true;
	}

	return false;
}
