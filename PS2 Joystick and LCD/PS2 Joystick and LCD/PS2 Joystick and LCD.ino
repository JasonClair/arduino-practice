/*
 Name:			PS2_Joystick_and_LCD.ino
 Created:		8/26/2018 1:42:26 PM
 Author:		qurator
 Description:	Read temperature using a LM35 sensor & display on a LCD screen.
				PS2 JoyStick input used to determine where to show the information
				and whether to show Celcius or Farenhite
*/

// the setup function runs once when you press reset or power the board
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int tempPin = 2;
int xPin = A0;
int yPin = A1;
int swPin = 8;


void setup() {
	lcd.begin(16, 2);
	pinMode(swPin, INPUT);
	digitalWrite(swPin, HIGH);
	Serial.begin(9600);
}

void loop() {
	lcd.clear();
	int lcdCol = 0;
	int lcdRow = 0;
	Serial.println("Values:");
	Serial.println(analogRead(xPin), DEC);
	Serial.println(analogRead(yPin), DEC);
	Serial.println(digitalRead(swPin));

	if (analogRead(xPin) < 500) {
		lcdCol = 0;
	}
	else if (analogRead(xPin) > 500 && analogRead(xPin) <= 520) {
		lcdCol = 2;
	}
	else if (analogRead(xPin) > 520) {
		lcdCol = 4;
	}

	if (analogRead(yPin) <= 510) {
		lcdRow = 0;
	}
	else {
		lcdRow = 1;
	}
	bool useCelcius = digitalRead(swPin);

	lcd.setCursor(lcdCol, lcdRow);
	lcd.print(getTempFormatted(useCelcius));
	delay(1000);
}

// return the temperature with units
String getTempFormatted(bool useCelcius) {
	float temp = getTempValue(useCelcius);
	String text;
	text += temp;
	text += useCelcius ? "*c" : "*f";
	return text;
}

float getTempValue(bool useCelcius) {
	float temp;
	temp = analogRead(tempPin);
	float celcius = temp * 0.48828125;
	if (useCelcius) {
		return celcius;
	}
	else {
		float fahr = (celcius * 9) / 5 + 32;
		return fahr;
	}
}
