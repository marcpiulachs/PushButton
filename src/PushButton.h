/*******************************************************************************
DebouncedButtons Arduino library http://libahunt.ee/debouncedbuttons
by Anna Jõgi a.k.a Libahunt
Public domain
*******************************************************************************/
#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include "Arduino.h"

// Format of command callback functions
typedef void(*buttonPressCallback)();

class PushButton 
{
  public:
  
		PushButton(int pinNumber, unsigned long debounceDelay, buttonPressCallback func);
		boolean isPressed();
		void check();
		
	private:
		unsigned long debounceTime;
		int buttonState;
		int pin;
	    unsigned long dbDelay;
		boolean lastDbState;
		unsigned long lastDbTime;
		boolean value;
		buttonPressCallback callback;
};
#endif
