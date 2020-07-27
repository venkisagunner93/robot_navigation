/**
 * @file planner.h
 * @author Venkatavaradhan Vembanoor Lakshmi Narayanan (venkatavaradhan93@gmail.com)
 * @brief A class for orchestrating planning and navigation
 * @version 0.1
 * @date 2020-07-26
 * @copyright Copyright (c) 2020
 */

#ifndef PLANNER_H
#define PLANNER_H

#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>
#include <std_srvs/Trigger.h>
#include "navigation/global_planner/global_planner.h"
#include "navigation/global_planner/breadth_first_search.h"
#include "robot/car_robot.h"

/**
 * @brief A class for orchestrating planning and navigation
 */
class Planner
{
    public:
        /**
         * @brief Construct a new Planner object
         * @param nh - ROS NodeHandle for communication
         * @param robot - Robot base class instance
         */
        Planner(ros::NodeHandle& nh, Robot* robot);
        /**
         * @brief Destroy the Planner object
         */
        ~Planner();
        /**
         * @brief A method to update robot pose
         */
        void updateRobotPose();
    
    private:
        /**
         * @brief Robot
         */
        Robot* robot_;
        /**
         * @brief Breadth first search instance
         */
        BFS bfs_;
        /**
         * @brief Map subscriber
         */
        ros::Subscriber map_subscriber_;
        /**
         * @brief Global path publisher
         */
        ros::Publisher global_path_publisher_;
        /**
         * @brief Global path service
         */
        ros::ServiceServer global_path_service_;
        /**
         * @brief A callback to load map from map server
         * @param msg - Occupancy grid
         */
        void getMap(const nav_msgs::OccupancyGrid& msg);
        /**
         * @brief A callback to get global path
         * @param request 
         * @param response 
         * @return true 
         * @return false 
         */
        bool getGlobalPath(std_srvs::TriggerRequest& request, std_srvs::TriggerResponse& response);
};

#endif  // PLANNER_H
