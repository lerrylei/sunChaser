#include <Servo.h>

// motor/joystick constants
int enableAPin = 3;
int in1Pin = 4;
int in2Pin = 5;
int enableBPin = 8;
int in4Pin = 9;
int in3Pin = 10;

// solar tracker constants
Servo horizontal; // horizontal servo
int servoh = 90;
int servohLimitHigh = 20;
int servohLimitLow = 160;

Servo vertical; // vertical servo
int servov = 90;
int servovLimitHigh = 60;
int servovLimitLow = 120;

// photoresistor pin connections
int topleft = A2; // yellow
int topright = A1; // orange
int botleft = A3; // green
int botright = A4; // blue


void setup() {
  pinMode(enableAPin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);

  horizontal.attach(12);
  vertical.attach(13);

  Serial.begin(9600);
}

void loop() {
  motorControl();

  // intiate servos
  horizontal.write(80);
  vertical.write(90);

  solarTrack();
  
  // debugging photoresistors 
  // int tlVal = analogRead(topleft);
  // int trVal = analogRead(topright);
  // int blVal = analogRead(botleft);
  // int brVal = analogRead(botright);

  // Serial.println(tlVal);
  // Serial.println(trVal);
  // Serial.println(blVal);
  // Serial.println(brVal);
  // Serial.println(" ");
}

void motorControl() {
  int motorPWMSpeed = 0;
  int joystickValue = analogRead(A0);   //Joystick gives values ranging from 0 to 1023. So we will consider center value as 512 and lets keep some deadband at center.

  if (joystickValue >= 530)           //This will move motor in forward direction
  {
    motorPWMSpeed = map(joystickValue, 530, 1023, 0, 255);
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
    analogWrite(enableAPin, motorPWMSpeed);

    digitalWrite(in4Pin, HIGH);
    digitalWrite(in3Pin, LOW);
    analogWrite(enableBPin, motorPWMSpeed);
  }
  else if (joystickValue <= 490)      //This will move motor in reverse direction
  {
    motorPWMSpeed = map(joystickValue, 490, 0, 0, 255);
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
    analogWrite(enableAPin, motorPWMSpeed);

    digitalWrite(in4Pin, LOW);
    digitalWrite(in3Pin, HIGH);
    analogWrite(enableBPin, motorPWMSpeed);
  }
  else                                 //Stop the motor
  {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, LOW);
    digitalWrite(in4Pin, LOW);
    digitalWrite(in3Pin, LOW);
  }
} 

void solarTrack() {
  int lt = analogRead(topleft); // top left
  int rt = analogRead(topright); // top right
  int ld = analogRead(botleft); // down left
  int rd = analogRead(botright); // down right
  int dtime = 50; int tol = 90; // dtime=diffirence time, tol=toleransi
  int avt = (lt + rt) / 2; // average value top
  int avd = (ld + rd) / 2; // average value down
  int avl = (lt + ld) / 2; // average value left
  int avr = (rt + rd) / 2; // average value right
  int dvert = avt - avd; // check the diffirence of up and down
  int dhoriz = avl - avr;// check the diffirence og left and rigt

  if (-1*tol > dvert || dvert > tol) {
    if (avt > avd) {
      servov = ++servov;
    if (servov > servovLimitHigh)
      {servov = servovLimitHigh;}
    }
  else if (avt < avd)
    {servov= --servov;
    if (servov < servovLimitLow)
      { servov = servovLimitLow;}
    }
    vertical.write(servov);
  }
  if (-1*tol > dhoriz || dhoriz > tol) // check if the diffirence is in the tolerance else change horizontal angle
  {
    if (avl > avr) {
      servoh = ++servoh;
      delay(20);
      if (servoh < servohLimitLow) {
        servoh = servohLimitLow;
      }
    }
    else if (avl < avr) {
      servoh = --servoh;
      delay(20);
      if (servoh > servohLimitHigh) {
        servoh = servohLimitHigh;
      }
    }
    else if (avl = avr) {
      delay(5000);
      }
    horizontal.write(servoh);
    }
  delay(dtime); 
}
