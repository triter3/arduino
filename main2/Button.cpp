#include "Button.h"
#include <Arduino.h>

Button::Button(int number, int pin, int min_val, int max_val){
	pinMode(pin, INPUT);
	_number = number;
  _pin = pin;
  _minVal = min_val;
  _maxVal = max_val;
	afterTime = millis();
}

bool Button::check(){
	val = analogRead(_pin);
	nowTime = millis();
	if (val <= _maxVal && val >= _minVal && (nowTime - afterTime)>= 1000){
		afterTime = millis();
		return true;
	}
	return false;
}

int Button::getNumber(){
  return _number;
}

