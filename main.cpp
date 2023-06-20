
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftBack             motor         11              
// LeftMid              motor         12              
// LeftFront            motor         13              
// RightBack            motor         20              
// RightMid             motor         19              
// RightFront           motor         18              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

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

void usercontrol(void) {
  // User control code here, inside the loop

    motor_group LeftDriveGroup = motor_group(LeftFront, LeftMid, LeftBack);
    motor_group RightDriveGroup = motor_group(RightFront, RightMid, RightBack);  

    while(1){ 
      
      //drive forward
      if(Controller1.Axis3.value()>>2){
        LeftDriveGroup.spin(reverse, 0.70 * Controller1.Axis3.value(),pct);
        RightDriveGroup.spin(forward, 0.70 * Controller1.Axis3.value(),pct);
      }
      //turn
      else if(Controller1.Axis1.value()>>2){
        LeftDriveGroup.spin(reverse,0.70 * Controller1.Axis1.value(),pct);
        RightDriveGroup.spin(reverse,0.70 * Controller1.Axis1.value(),pct);
      }
      else {
        LeftDriveGroup.stop(brake);
        RightDriveGroup.stop(brake);
      } 
      //shooting piston

    }
}

//
// Main will set up the competition functions and callbacks.
//
int main(){
  // Set up callbacks for autonomous and driver control periods.
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
