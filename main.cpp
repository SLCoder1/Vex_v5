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
// Controller1          controller                    
// LeftFront            motor         4               
// LeftMid              motor         5               
// LeftBack             motor         3               
// RightFront           motor         7               
// RightMid             motor         9               
// RightBack            motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
 
const int wheelTravel = 319;
const int trackWidth = 300;
const int wheelBase = 273;
//160

motor_group LeftDriveGroup = motor_group(LeftFront, LeftMid, LeftBack);
motor_group RightDriveGroup = motor_group(RightFront, RightMid, RightBack);  

drivetrain Drivetrain(LeftDriveGroup, RightDriveGroup, wheelTravel, trackWidth, wheelBase, mm);

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void usercontrol(void) {
  // User control code here, inside the loop 

    while(1){ 
      
      //drive forward
      if(Controller1.Axis3.value()>>2){
        LeftDriveGroup.spin(forward, 0.70 * Controller1.Axis3.value(),pct);
        RightDriveGroup.spin(forward, 0.70 * Controller1.Axis3.value(),pct);
      }
      //turn
      else if(Controller1.Axis1.value()>>2){
        LeftDriveGroup.spin(forward,0.70 * Controller1.Axis1.value(),pct);
        RightDriveGroup.spin(reverse,0.70 * Controller1.Axis1.value(),pct);
      }
      else {
        LeftDriveGroup.stop(brake);
        RightDriveGroup.stop(brake);
      } 
      //shooting piston
      wait(20,msec);
    }
}

void autonomous(void) {

  Drivetrain.setDriveVelocity(50, percent);

  Drivetrain.driveFor(forward,1,inches);
  wait(100, msec);
  Drivetrain.turnFor(5.5, degrees, true);
  wait(100, msec);
  Drivetrain.setDriveVelocity(60, percent);
  Drivetrain.driveFor(forward,7,inches);
  //release triball

  Drivetrain.driveFor(reverse,3,inches, true);
  // Drivetrain.turnFor(-6, degrees, true);
  
  // Drivetrain.driveFor(forward,7,inches, true);
  // Drivetrain.turnFor(6, degrees, true);
  // Drivetrain.driveFor(forward,7,inches, true);
  // //intake
  // Drivetrain.turnFor(-6, degrees, true);
  // Drivetrain.turnFor(6, degrees, true);

  // Drivetrain.driveFor(forward,3,inches, true);
  // //intake
  // Drivetrain.turnFor(-3, degrees, true);
  // Drivetrain.turnFor(3, degrees, true);

}


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
