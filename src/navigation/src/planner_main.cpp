#include "navigation/planner.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "planner");
  ros::NodeHandle nh;

  DriveLimits limits;
  limits.max_linear_velocity = 0.25;         // (m/s)
  limits.max_angular_velocity = 0.1745;      // (rad/s)
  limits.max_linear_acceleration = 1.0;      // (m/s^2)
  limits.max_angular_acceleration = 0.7854;  // (rad/s^2)
  limits.max_steering_angle = 0.5235;        // (rad)

  CarRobot car_robot(limits);
  car_robot.displayRobotDetails();

  Planner planner(nh);

  ControlInput input;

  while (ros::ok())
  {
    planner.planMotion();
    car_robot.executeCommand(input);
    ros::spinOnce();
    ros::Duration(0.1).sleep();
  }

  return 0;
}