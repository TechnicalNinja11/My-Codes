/* Code By Technical Ninja (Avinash Damse) */
#include<AFMotor.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


int motorSpeed=125;
int turn=50;

void setup() {
  Serial.begin(9600);
  Serial.flush();
 
}

void loop() {
  String input="";
  while(Serial.available()){
    input+=(char)Serial.read();
    delay(5);
  }
  
  if(input=="n"){
    stp();
  }
  else if(input=="f"){
    fwd();
  }
  else if(input=="b"){
    rev();
  }
  
     else if(input=="l"){
  lft();
  }
  else if(input=="r"){
  rght();
  }
  
  else if(input!=""){
    motorSpeed=input.toInt();
  }
}

void fwd(){
  
   motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 

}

void rev(){
 

  motor1.setSpeed(255); 
  motor1.run(FORWARD); 
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
  motor3.setSpeed(255);
  motor3.run(FORWARD); 
  motor4.setSpeed(255);
  motor4.run(FORWARD); 

}

void lft(){
  motor1.setSpeed(255); 
  motor1.run(FORWARD); 
   motor2.setSpeed(255);
  motor2.run(FORWARD); 
   motor3.setSpeed(255);
  motor3.run(BACKWARD);  
   motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
  
}
void rght(){
   motor1.setSpeed(255);
  motor1.run(BACKWARD); 
   motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
   motor3.setSpeed(255);
  motor3.run(FORWARD); 
  motor4.setSpeed(255);
  motor4.run(FORWARD); 

  
 
  
}

void stp(){
  motor1.setSpeed(0); 
  motor1.run(RELEASE); 
  motor2.setSpeed(0); 
  motor2.run(RELEASE); 
  motor3.setSpeed(0); 
  motor3.run(RELEASE); 
  motor4.setSpeed(0); 
  motor4.run(RELEASE); 
}
