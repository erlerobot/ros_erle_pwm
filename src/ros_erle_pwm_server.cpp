#include "ros/ros.h"
#include "ros_erle_pwm/pwm.h"

#include "RC_Channel.h"

#define NUM_PWM 8

RC_Channel* c[NUM_PWM];

void copy_input_output(void)
{
	for (int i = 0; i < NUM_PWM; i++){

    	c[i]->servo_out = c[i]->control_in;
    	c[i]->calc_pwm();
    	c[i]->output();
  	}
}


void PWMCallback(const ros_erle_pwm::pwm::ConstPtr& msg)
{
  	ROS_INFO("I heard: PWM1:[%d], PWM2:[%d], PWM3:[%d], PWM4:[%d], PWM5:[%d], PWM6:[%d], PWM7:[%d], PWM8:[%d]",
  		 msg->PWM_1, msg->PWM_2, msg->PWM_3, msg->PWM_4,
  		 msg->PWM_5, msg->PWM_6, msg->PWM_7, msg->PWM_8);

	c[0]->set_pwm(msg->PWM_1);
	c[1]->set_pwm(msg->PWM_2);
	c[2]->set_pwm(msg->PWM_3);
	c[3]->set_pwm(msg->PWM_4);
	c[4]->set_pwm(msg->PWM_5);
	c[5]->set_pwm(msg->PWM_6);
	c[6]->set_pwm(msg->PWM_7);
	c[7]->set_pwm(msg->PWM_8);

	copy_input_output();
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pwm");

  for (int i = 0; i < NUM_PWM; i++){
  	c[i] = new RC_Channel(i);
  	c[i]->set_range(0,1000);
    c[i]->set_type(RC_CHANNEL_TYPE_RANGE);
    c[i]->enable_out();
  }

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("pwm", 1000, PWMCallback);

  ros::spin();

  return 0;
}

