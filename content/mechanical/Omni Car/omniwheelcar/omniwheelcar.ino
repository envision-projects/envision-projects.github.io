#include <Adafruit_MotorShield.h>
#include <IBusBM.h>

IBusBM IBus; // IBus object
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *LF = AFMS.getMotor(1);
Adafruit_DCMotor *LB = AFMS.getMotor(2);
Adafruit_DCMotor *RF = AFMS.getMotor(3);
Adafruit_DCMotor *RB = AFMS.getMotor(4); 

int lside;
int rside;

int maxturn = 200;
int maxspd = 200;

void runMotor(Adafruit_DCMotor *motor, int val){
  if (val > 0)  
    motor->run(FORWARD);
  else
    motor->run(BACKWARD);
  val = abs(val);
  if (val > 255)
    val = 255;
  motor->setSpeed(val);
}

void setup() {
  Serial.begin(9600);       
  IBus.begin(Serial1);    // iBUS connected to pin 19 

  if (!AFMS.begin()) {      
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");  

}

void loop() {
  int ry = map(IBus.readChannel(1), 1000, 2000, -maxspd, maxspd);
  int lx = map(IBus.readChannel(3), 1000, 2000, -maxturn, maxturn);

  lside = 0; rside = 0;

  lside = ry + lx; rside = ry - lx;

  if (IBus.readChannel(1) != 0) {
    runMotor(LF, lside);
    runMotor(LB, lside);
    runMotor(RF, rside);
    runMotor(RB, rside);
  }

}