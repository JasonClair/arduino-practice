/*
 Name:			Ultrasonic_Sensor_with_Servo_and_LCD.ino
 Created:		8/26/2018 2:07:02 PM
 Author:		qurator
 Description:	Ultrasonic Sensor sat on top of a Servo. The code moves the servo based on a loop. The Ultrasonic Sensor input is displayed
				on a LCD screen to show the distance to any objects in front of the sensor. 
*/


#include <LiquidCrystal.h> // includes the LiquidCrystal Library
#include <Servo.h>

Servo servo;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;

void setup() {

	lcd.begin(16, 2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	servo.attach(7);
}

void loop() {
	// rotates the servo motor from 15 to 165 degrees
	for (int i = 15; i <= 165; i++) {
		servo.write(i);
		delay(30);
		digitalWrite(trigPin, LOW);
		delayMicroseconds(2);
		digitalWrite(trigPin, HIGH);
		delayMicroseconds(10);
		digitalWrite(trigPin, LOW);
		duration = pulseIn(echoPin, HIGH);
		distanceCm = duration * 0.034 / 2;
		distanceInch = duration * 0.0133 / 2;
		lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed
		lcd.print("Distance: "); // Prints string "Distance" on the LCD
		lcd.print(distanceCm); // Prints the distance value from the sensor
		lcd.print(" cm");
		delay(10);
		lcd.setCursor(0, 1);
		lcd.print("Distance: ");
		lcd.print(distanceInch);
		lcd.print(" inch");
		delay(10);
	}
}
