#ifndef _TURTLEBOTMOVE_H_
#define _TURTLEBOTMOVE_H_

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>

class Turtlebot{
private:
	ros::Publisher odom_pub;
	ros::Publisher pub;
	ros::NodeHandle nh;

public:
	Turtlebot(std::string velocityTopic, std::string odometryTopic){
		this->pub = nh.advertise<geometry_msgs::Twist>(velocityTopic, 1);
		this->odom_pub = nh.advertise<nav_msgs::Odometry>(odometryTopic, 50);
	}
	~Turtlebot(){
		
	}

	void singleVelocityMessage(float linearVelocity, float angularVelocity){
		geometry_msgs::Twist msg;
		msg.linear.x = linearVelocity;
		msg.angular.z = angularVelocity;
		pub.publish();
	}

	void moveForSeconds(int numSeconds, float linearVelocity, float angularVelocity){
		geometry_msgs::Twist msg;
		msg.linear.x = linearVelocity;
		msg.angular.z = angularVelocity;
		ros::Time begin = ros::Time::now();
		while(ros::Time::now() - begin <= ros::Duration(numSeconds) && ros::ok()){
			pub.publish(msg);
		}
	}

	void moveForSeconds(int numSeconds, geometry_msgs::Twist message){
		moveForSeconds(numSeconds, message.linear.x, message.angular.z);
	}

	bool moveMeters(float dx, float dy){
		typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
		//tell the action client that we want to spin a thread by default
  		MoveBaseClient ac("move_base", true);
  		//wait for the action server to come up
		while(!ac.waitForServer(ros::Duration(5.0)) && ros::ok()){
			ROS_INFO("Waiting for the move_base action server to come up");
		}

		move_base_msgs::MoveBaseGoal goal;
		goal.target_pose.pose.position.x = dx;
		goal.target_pose.pose.position.y = dy;
  		goal.target_pose.pose.orientation.w = 1.0;
  		ac.sendGoal(goal);
  		ac.waitForResult();

  		if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) return true;
  		else return false;
	}

	bool moveCentimeters(float dx, float dy){
		return moveMeters(dx / 100, dy / 100);
	}
};

#endif