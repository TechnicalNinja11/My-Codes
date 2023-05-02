/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu March 15 2023                                         */
/*    Description:  Competition Template                                      */
/*    Avinash Damse CSUN CE                                                   */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
brain Brain;

vex::motor      RightRear(vex::PORT19, vex::gearSetting::ratio18_1, true);
vex::motor      LeftRear(vex::PORT13, vex::gearSetting::ratio18_1, true);
vex::motor      RightFront(vex::PORT20, vex::gearSetting::ratio18_1, true);
vex::motor      LeftFront(vex::PORT11, vex::gearSetting::ratio18_1, true);
vex::motor      RightMid(vex::PORT18, vex::gearSetting::ratio18_1, false);
vex::motor      LeftMid(vex::PORT12, vex::gearSetting::ratio18_1, false);
vex::motor      intake_motor(vex::PORT2, vex::gearSetting::ratio18_1, false);
vex::motor      catapult_motor(vex::PORT14, vex::gearSetting::ratio36_1, true);
vex::motor      catapult_motor1(vex::PORT15, vex::gearSetting::ratio36_1, false);
vex::motor      Roller_motor(vex::PORT1, vex::gearSetting::ratio36_1, true);

vex::controller Controller1(vex::controllerType::primary);

limit catl = limit(Brain.ThreeWirePort.H);
pneumatics boost = pneumatics(Brain.ThreeWirePort.F);
pneumatics expand = pneumatics(Brain.ThreeWirePort.E);
pneumatics block = pneumatics(Brain.ThreeWirePort.G);
void driveM();
void catload();
bool loaded;



//public vex::pneumatics::pneumatics(triport::port &port)


//vex::limit::   limit(	triport::port & 	A	);

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  
  RightFront.startRotateFor(directionType::rev, -0.25, rotationUnits::rev, 100, velocityUnits::pct);
  LeftFront.startRotateFor(directionType::fwd, -0.25, rotationUnits::rev, 100, velocityUnits::pct);
  LeftRear.startRotateFor(directionType::fwd, -0.25, rotationUnits::rev, 100, velocityUnits::pct);
  RightRear.startRotateFor(directionType::rev, -0.25, rotationUnits::rev, 100, velocityUnits::pct);
  LeftMid.startRotateFor(directionType::fwd, -0.25, rotationUnits::rev, 100, velocityUnits::pct);
  RightMid.rotateFor(directionType::rev, -0.25, rotationUnits::rev, 100, velocityUnits::pct);


  wait(250,msec);

  Roller_motor.rotateFor(directionType::rev, 0.20, rotationUnits::rev, 100, velocityUnits::pct);

  RightFront.startRotateFor(directionType::rev, 0.25, rotationUnits::rev, 100, velocityUnits::pct);
  LeftFront.startRotateFor(directionType::fwd, 0.25, rotationUnits::rev, 100, velocityUnits::pct);
  LeftRear.startRotateFor(directionType::fwd, 0.25, rotationUnits::rev, 100, velocityUnits::pct);
  RightRear.startRotateFor(directionType::rev, 0.25, rotationUnits::rev, 100, velocityUnits::pct);
  LeftMid.startRotateFor(directionType::fwd, 0.25, rotationUnits::rev, 100, velocityUnits::pct);
  RightMid.rotateFor(directionType::rev, 0.25, rotationUnits::rev, 100, velocityUnits::pct);
  //wait(250,msec);

  //RightFront.startRotateFor(directionType::fwd, -0.25, rotationUnits::rev, 100, velocityUnits::pct);
 // LeftFront.startRotateFor(directionType::rev, -0.25, rotationUnits::rev, 100, velocityUnits::pct);
 // LeftRear.startRotateFor(directionType::rev, -0.25, rotationUnits::rev, 100, velocityUnits::pct);
 // RightRear.rotateFor(directionType::fwd, -0.25, rotationUnits::rev, 100, velocityUnits::pct);


  

  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {

    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    boost.open();
    int a3 = Controller1.Axis3.position(pct) * 120;
    
    int a1 = Controller1.Axis1.position(pct) * 120;

  if((abs(a3) > 960) || (abs(a1) > 960)){
    RightFront.spin(reverse, -a3  - a1, voltageUnits::mV);
    LeftFront.spin(reverse, a3  - a1, voltageUnits::mV);
    RightRear.spin(reverse, -a3  - a1, voltageUnits::mV);
    LeftRear.spin(reverse, a3  - a1, voltageUnits::mV);
    RightMid.spin(reverse, -a3  - a1, voltageUnits::mV);
    LeftMid.spin(reverse, a3  - a1, voltageUnits::mV);
  } else {
    RightFront.spin(fwd, 0, voltageUnits::mV);
    LeftFront.spin(fwd, 0, voltageUnits::mV);
    RightRear.spin(fwd, 0, voltageUnits::mV);
    LeftRear.spin(fwd, 0, voltageUnits::mV);
    RightMid.spin(fwd, 0, voltageUnits::mV);
    LeftMid.spin(fwd, 0, voltageUnits::mV);
  }


  if(Controller1.ButtonR1.pressing()){
          intake_motor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct ); 
          }
          else if(Controller1.ButtonDown.pressing()){
          intake_motor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct ); 
          }
          else{
          intake_motor.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct );
          }


  

  if(Controller1.ButtonL2.pressing()){
          Roller_motor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct ); 
          }
         else if(Controller1.ButtonUp.pressing()){
          Roller_motor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct ); 
          }
          else{
          Roller_motor.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct );
          }

  


  if(Controller1.ButtonX.pressing()){
          boost.open();
  }
  else{
          boost.close();
  }

  if(Controller1.ButtonB.pressing()){
          block.open();
  }
  else{
          block.close();
  }

  if(Controller1.ButtonY.pressing()){
          expand.open();
  }
  else{
          expand.close();
  }

  if(Controller1.ButtonL1.pressing() && !catl.pressing()){
          catapult_motor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct ); 
          catapult_motor1.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct );
          catapult_motor.setBrake(hold);
          catapult_motor1.setBrake(hold);
  }else if(Controller1.ButtonR2.pressing() && catl.pressing()){
          
          catapult_motor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct );     
  }
  else{
          catapult_motor.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct );
          catapult_motor1.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct );
  }
  if(Controller1.ButtonR2.pressing() && catl.pressing()){
          catapult_motor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct );
           catapult_motor1.spin(vex::directionType::rev, 100, vex::velocityUnits::pct ); 
           
          }
          /*else{
          catapult_motor.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct );
          catapult_motor.setBrake(hold);
          }*/

  if(catl.pressing()){
    loaded = true;
  }else{
    loaded = false;
  }  

  if(!loaded){
    driveM();
    catload();
  } 
  


    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}

void driveM() {

   int a3 = Controller1.Axis3.position(pct) * 120;
    
    int a1 = Controller1.Axis1.position(pct) * 120;

  if((abs(a3) > 960) || (abs(a1) > 960)){
    RightFront.spin(reverse, a3  - a1, voltageUnits::mV);
    LeftFront.spin(reverse, -a3  - a1, voltageUnits::mV);
    RightRear.spin(reverse, a3  - a1, voltageUnits::mV);
    LeftRear.spin(reverse, -a3  - a1, voltageUnits::mV);
    RightMid.spin(reverse, a3  - a1, voltageUnits::mV);
    LeftMid.spin(reverse, -a3  - a1, voltageUnits::mV);
  } else {
    RightFront.spin(fwd, 0, voltageUnits::mV);
    LeftFront.spin(fwd, 0, voltageUnits::mV);
    RightRear.spin(fwd, 0, voltageUnits::mV);
    LeftRear.spin(fwd, 0, voltageUnits::mV);
    RightMid.spin(fwd, 0, voltageUnits::mV);
    LeftMid.spin(fwd, 0, voltageUnits::mV);
  }
  return;
}

void catload() {

  if(!catl.pressing()){
          catapult_motor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct ); 
          catapult_motor1.spin(vex::directionType::rev, 100, vex::velocityUnits::pct );
          catapult_motor.setBrake(hold);
          catapult_motor1.setBrake(hold);
  }
  else{
          catapult_motor.spin(vex::directionType::rev, 0, vex::velocityUnits::pct );
          catapult_motor1.spin(vex::directionType::rev, 0, vex::velocityUnits::pct );
  }
}


