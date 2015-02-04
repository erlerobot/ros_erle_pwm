#include "ros/ros.h"
#include "ros_erle_pwm/pwm.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ros_erle_pwm_client");
  if (argc != 9){
    ROS_INFO("usage: ros_erle_pwm_client PWM_1 PWM_2 PWM_3 PWM_4 PWM_5 PWM_6 PWM_7 PWM_8");
    return 1;
  }

  ros::NodeHandle n;
  ros::Publisher led_pub = n.advertise<ros_erle_pwm::pwm>("statusled", 1000);
  ros_erle_pwm::pwm msg;

  msg.PWM_1 = atoi(argv[1]);
  msg.PWM_2 = atoi(argv[2]);
  msg.PWM_3 = atoi(argv[3]);
  msg.PWM_4 = atoi(argv[4]);
  msg.PWM_5 = atoi(argv[5]);
  msg.PWM_6 = atoi(argv[6]);
  msg.PWM_7 = atoi(argv[7]);
  msg.PWM_8 = atoi(argv[8]);

//  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok()){
    led_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }  
  return 0;
}
