int xPin = A0;
int yPin = A1;
int swPin = 8;

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(swPin, INPUT);
	digitalWrite(swPin, HIGH);
	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
	Serial.print("X: ");
	Serial.print(analogRead(xPin), DEC);
	Serial.print("|Y: ");
	Serial.print(analogRead(yPin), DEC);
	Serial.print("|Z: ");
	Serial.println(digitalRead(swPin));
	delay(500);
}
