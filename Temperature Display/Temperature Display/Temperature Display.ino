/*
	 Name:			Temperature_Display.ino
	 Created:		8/26/2018
	 Author:		Qurator
	 Description:	Read input from a LM35 sensor and display onto a 1602a LCD
*/

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int tempPin = 1;
float temp;

// the setup function runs once when you press reset or power the board
void setup() {
	lcd.begin(16, 2);
}

// the loop function runs over and over again until power down or reset
void loop() {
	temp = analogRead(tempPin);
	// 500mV / 1024 = 0.48828125
	temp = temp * 0.48828125;
	String text;
	text += "Temp = ";
	text += temp;
	text += "*c";
	lcd.setCursor(0, 0);
	lcd.print(text);


	delay(1000);
}
