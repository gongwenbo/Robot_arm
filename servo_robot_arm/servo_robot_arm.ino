/*
gongwenbo at tarsbot 
2015.11.11
*/
#include <Servo.h> 
#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <serve_logitech/all_sensor.h>

Servo servo_right;
Servo servo_left;
ros::NodeHandle  nh;
float angle_right;
float angle_left;
serve_logitech::all_sensor str_msg;
//ros::Publisher chatter("chatter_1", &str_msg);

void servo_cb ( const serve_logitech::all_sensor& msg)
{
  angle_right=(msg.b_f +1)*100;
  angle_right= map(angle_right, 0, 200, 0, 180);
  angle_left=(msg.a_f +1)*100;
  angle_left= map(angle_left, 0, 200, 0, 180);
  
  servo_right.write(angle_right);
  servo_left.write(angle_left);
   
  
}

ros::Subscriber<serve_logitech::all_sensor> sub("server_logitech", servo_cb);

void setup()
{
  //Serial.begin(9600);	//设置通讯的波特率为9600
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  //nh.advertise(chatter);
  servo_right.attach(10); //attach it to pin 9
  servo_left.attach(9); //attach it to pin 9
 
}

 void loop()
 {
  nh.spinOnce();
  /*
  angle_right= map(angle_right, 0, 200, 0, 180); 
  angle_left= map(angle_left, 0, 200, 0, 180);
  
  servo_right.write(angle_right); //set servo angle, should be from 0-180  
  //delay(1);
  servo_left.write(angle_left); 
  //delay(1);
  */

  
}
