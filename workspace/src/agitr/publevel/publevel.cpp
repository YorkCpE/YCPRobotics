#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

int main(int argc, char** argv){

	ros::init(argc, argv, "publish_velocity");
	ros::NodeHandle nh;
	ros::Publisher pub= nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",1000);
	srand(time(0));
	ros::Rate rate(2);
	int count =0;
	while(ros::ok()){
		geometry_msgs::Twist msg;
		if(count >=0 && count <13 ){
			msg.linear.x= .5;//double(rand())/double(RAND_MAX);
			msg.angular.z= 0;//2*double(rand())/double(RAND_MAX)-1;
			count= count+1;
		}
		else if(count >=13 && count <17 ){
			msg.linear.x= 0;//double(rand())/double(RAND_MAX);
			msg.angular.z= 1;//2*double(rand())/double(RAND_MAX)-1;
			count= count+1;
		}
		else if(count >=17 && count <29 ){
			msg.linear.x= .5;//double(rand())/double(RAND_MAX);
			msg.angular.z= 0;//2*double(rand())/double(RAND_MAX)-1;
			count= count+1;
		}
		else if(count >=29 && count <33 ){
			msg.linear.x= 0;//double(rand())/double(RAND_MAX);
			msg.angular.z= 1.1;//2*double(rand())/double(RAND_MAX)-1;
			count= count+1;
		}
		else if(count >=33 && count <45 ){
			msg.linear.x= .5;//double(rand())/double(RAND_MAX);
			msg.angular.z= 0;//2*double(rand())/double(RAND_MAX)-1;
			count= count+1;
		}
		pub.publish(msg);
		ROS_INFO_STREAM("sending velocity command:"
		  << "linearX=" << msg.linear.x
		  << "linearY=" << msg.linear.y
		  << "linearZ=" << msg.linear.z
		  << "angular=" << msg.angular.z);
		rate.sleep();
	}
}
