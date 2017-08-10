#include "ros/ros.h"
#include "mastering_ros_demo_pkg/demo_msg.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv){

	ros::init(argc, argv, "demo_msg_publisher");
	ros::NodeHandle node_obj;
	ros::Publisher msg_publisher = node_obj.advertise<mastering_ros_demo_pkg::demo_msg>("/demo_msg_topic", 10);
	ros::Rate loop_rate(10);
	int number_count = 0;

	while(ros::ok()){
		
		mastering_ros_demo_pkg::demo_msg msg;
		msg.greeting = "hello world";
		msg.number = number_count;

		ROS_INFO("%d", msg.number);
		ROS_INFO("%s", msg.greeting.c_str());

		msg_publisher.publish(msg);

		ros::spinOnce();
		loop_rate.sleep();

		++number_count;
	}

	return 0;
}
