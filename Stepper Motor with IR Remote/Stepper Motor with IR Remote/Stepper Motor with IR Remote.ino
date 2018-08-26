// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
Name:       IR Receiver.ino
Created:	19/08/2018 16:07:03
Author:     Qurator
*/

#include <Stepper.h>
#include <IRremote.h>

#define CH1 0xFFA25D 
#define CH 0xFF629D
#define CH2 0xFFE21D
#define PREV 0xFF22DD
#define NEXT 0xFF02FD
#define PLAYPAUSE 0xFFC23D
#define VOL1 0xFFE01F
#define VOL2 0xFFA857
#define EQ 0xFF906F
#define button0 0xFF6897
#define button100 0xFF9867
#define button200 0xFFB04F
#define button1 0xFF30CF
#define button2 0xFF18E7
#define button3 0xFF7A85
#define button4 0xFF10EF
#define button5 0xFF38C7
#define button6 0xFF5AA5
#define button7 0xFF42BD
#define button8 0xFF4AB5
#define button9 0xFF52AD

#define STEPS 32
int maxSteps = 2048;
bool pause = false;
Stepper stepper(STEPS, 8, 10, 9, 11);

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
int stepperVal = 0;

// The setup() function runs once each time the micro-controller starts
void setup()
{
	Serial.begin(9600);
	stepper.setSpeed(500);
	irrecv.enableIRIn();
}

// Add the main program code into the continuous loop() function
void loop()
{

	for (int step = 0; step < maxSteps; step++) {
		if (irrecv.decode(&results)) {
			handleButtonPress();
			irrecv.resume();
		}

		// If the application is paused, stop the motor
		if (!pause) {
			stepper.step(step);
		}
	}

}

void handleButtonPress() {
	Serial.println("button pressed");
	switch (results.value) {
	case CH1:
		Serial.println("CH1 pressed");
		break;
	case CH:
		Serial.println("CH pressed");
		break;
	case CH2:
		Serial.println("CH2 pressed");
		break;
	case PREV:
		Serial.println("Prev pressed");
		break;
	case NEXT:
		Serial.println("Next pressed");
		break;
	case PLAYPAUSE:
		Serial.println("Play pause pressed");
		pause = !pause;
		break;
	case VOL1:
		Serial.println("VOL1 pressed");
		break;
	case VOL2:
		Serial.println("VOL2 pressed");
		break;
	case EQ:
		Serial.println("EQ pressed");
		break;
	case button0:
		Serial.println("button 0 pressed");
		break;
	case button100:
		Serial.println("button 100 pressed");
		break;
	case button200:
		Serial.println("button 200 pressed");
		break;
	case button1:
		Serial.println("button 1 pressed");
		stepper.setSpeed(100);
		break;
	case button2:
		Serial.println("button 2 pressed");
		stepper.setSpeed(200);
		break;
	case button3:
		Serial.println("button 3 pressed");
		stepper.setSpeed(300);
		break;
	case button4:
		Serial.println("button 4 pressed");
		break;
	case button5:
		Serial.println("button 5 pressed");
		break;
	case button6:
		Serial.println("button 6 pressed");
		break;
	case button7:
		Serial.println("button 7 pressed");
		break;
	case button8:
		Serial.println("button 8 pressed");
		stepper.setSpeed(800);
		break;
	case button9:
		Serial.println("button 9 pressed");
		stepper.setSpeed(900);
		break;
	}
}


