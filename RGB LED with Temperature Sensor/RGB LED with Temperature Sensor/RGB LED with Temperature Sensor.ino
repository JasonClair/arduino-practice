const int RED_PIN = 7;
const int GREEN_PIN = 6;
const int BLUE_PIN = 5;

float temp;
int tempPin = 2;


void setup()
{
	pinMode(RED_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);
	Serial.begin(9600);
}


void loop()
{
	temp = analogRead(tempPin);
	// 500mV / 1024 = 0.48828125
	temp = temp * 0.48828125;
	Serial.print("Temperature = ");
	Serial.print(temp);
	Serial.print("*c");
	Serial.println();
	delay(1000);

	if (temp < 20) {
		digitalWrite(GREEN_PIN, LOW);
		digitalWrite(RED_PIN, LOW);
		digitalWrite(BLUE_PIN, HIGH);
	}
	else if (temp >= 20 && temp < 35) {
		digitalWrite(GREEN_PIN, HIGH);
		digitalWrite(BLUE_PIN, LOW);
		digitalWrite(RED_PIN, LOW);
	}
	else if (temp >= 35) {
		digitalWrite(GREEN_PIN, LOW);
		digitalWrite(BLUE_PIN, LOW);
		digitalWrite(RED_PIN, HIGH);
	}

}
