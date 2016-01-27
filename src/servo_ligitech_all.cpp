 #include "ros/ros.h"
 #include <geometry_msgs/Twist.h>
 #include <serve_logitech/all_sensor.h>
 #include <sensor_msgs/Joy.h>
 
 serve_logitech::all_sensor x;

 void chatterCallback(const sensor_msgs::Joy::ConstPtr& msg)
   {
     /*
     ROS_INFO("linear.x [%f]", msg->axes[5]);
     ROS_INFO("linear.y [%f]", msg->linear.y);
     ROS_INFO("linear.z [%f]", msg->linear.z);
     ROS_INFO("------------------------------");
     ROS_INFO("angular.x [%f]", msg->angular.x);
     ROS_INFO("angular.y [%f]", msg->angular.y);
     ROS_INFO("angular.z [%f]", msg->angular.z);
     ROS_INFO("******************************");
     */

     // ROS_INFO("linear.x [%f]", msg->axes[4]);
     x.b_f=msg->axes[4];
     x.a_f=msg->axes[3];
     ROS_INFO("x.a_f=%f",x.a_f);
     ROS_INFO("x.b_f=%f",x.b_f); 

    


   }
   
 int main(int argc, char **argv)
   {
     
     ros::init(argc, argv, "servo_ligitech_all");
   
     ros::NodeHandle n;
   
     ros::Subscriber sub = n.subscribe("joy", 1, chatterCallback);      //"teleop_velocity_smoother/raw_cmd_vel”为罗技手柄话题

     ros::Publisher chatter_pub = n.advertise<serve_logitech::all_sensor>("server_logitech", 1);
   
     ros::Rate loop_rate(10);

  while (ros::ok())

{

  chatter_pub.publish(x);
  ros::spinOnce();
  loop_rate.sleep();

}
    
     //ros::spin();
     
     return 0;
   }
