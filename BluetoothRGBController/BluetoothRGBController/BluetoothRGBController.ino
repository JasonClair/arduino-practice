/*
 Name:		BluetoothRGBController.ino
 Created:	9/8/2018 3:05:35 PM
 Author:	qurator
 Description: Recieve message from bluetooth module and change RGB LED colour
*/

String message; // Message from bluetooth
const int GREEN_PIN = 2;
const int BLUE_PIN = 3;
const int RED_PIN = 4;

void setup() {
	Serial.begin(9600);
	pinMode(GREEN_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);
	pinMode(RED_PIN, OUTPUT);
}

void SetColour() {
	Serial.print("Colour is: ");
	Serial.print(message);
	if (message.startsWith("green")) {
		Serial.println("Green selected");
		digitalWrite(GREEN_PIN, HIGH);
		digitalWrite(BLUE_PIN, LOW);
		digitalWrite(RED_PIN, LOW);
	}
	else if (message.startsWith("blue")) {
		Serial.println("Blue selected");
		digitalWrite(BLUE_PIN, HIGH);
		digitalWrite(GREEN_PIN, LOW);
		digitalWrite(RED_PIN, LOW);
	}
	else if (message.startsWith("red")) {
		Serial.println("Red selected");
		digitalWrite(RED_PIN, HIGH);
		digitalWrite(BLUE_PIN, LOW);
		digitalWrite(GREEN_PIN, LOW);
	}
}

void loop() {
  
	while (Serial.available()) {
		message += char(Serial.read());
	}

	if (!Serial.available()) {
		if (message != "") {
			SetColour();
			Serial.println(message);
			message = "";
		}
	}

	delay(1000);
}