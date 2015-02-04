#!/usr/bin/python
import rospy
import sys
from ros_erle_pwm.msg import *

PWM_1 = 0
PWM_2 = 0
PWM_3 = 0
PWM_4 = 0
PWM_5 = 0
PWM_6 = 0
PWM_7 = 0
PWM_8 = 0

def talker():
    pub = rospy.Publisher("pwm", pwm, queue_size=10)
    rospy.init_node("pwm", anonymous=True)
    msg.PWM_1 = PWM_1
    msg.PWM_2 = PWM_2
    msg.PWM_3 = PWM_3
    msg.PWM_4 = PWM_4
    msg.PWM_5 = PWM_5
    msg.PWM_6 = PWM_6
    msg.PWM_7 = PWM_7
    msg.PWM_8 = PWM_8
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        pub.publish(msg)
        rate.sleep()

def usage():
    return "%s [PWM_1 PWM_2 PWM_3 PWM_4 PWM_5 PWM_6 PWM_7 PWM_8]"%sys.argv[0]

if __name__ == "__main__":

    if len(sys.argv) == 9:
        PWM_1 = int(sys.argv[1])
        PWM_2 = int(sys.argv[2])
        PWM_3 = int(sys.argv[3])
        PWM_4 = int(sys.argv[4])
        PWM_5 = int(sys.argv[5])
        PWM_6 = int(sys.argv[6])
        PWM_7 = int(sys.argv[7])
        PWM_8 = int(sys.argv[8])
    else:
        print usage()
        sys.exit(1)
    talker();
