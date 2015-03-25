# ros-hydro-erle-pwm

ros-hydro-erle-pwm
------------------

Support forums and chats
------------------------

Please ask your questions not related to bugs/feauture requests on:

- [Erle Robotics Forum](http://forum.erlerobotics.com/)

We'd like to keep the project bugtracker as free as possible, so please contact via the above methods.

Programs
-------- 

```
rosrun ros_erle_pwm ros_erle_pwm_main
```

### Installing from source

```
cd ~/ros_catkin_ws/src
git clone https://github.com/ros_erle_pwm
cd ..
catkin_make_isolate
source devel_isolated/setup.bash
```
or 

```
cd ~/ros_catkin_ws/src

wstool init src 
set -t src ros_erle_statusled --git https://github.com/erlerobot/ros_erle_statusled
wstool update -t src
```
Then use regular `catkin_make_isolated` for build and install.

### Running examples
C++:
```
rosrun ros_erle_pwm ros_erle_buzzer_writer
```

Python:
```
rosrun ros_erle_pwm ros_erle_buzzer_writer.py
```

Links
-----

  - [Erle Robotics](www.erlerobotics.com)
  - [Erle-Brain](https://erlerobotics.com/blog/product/erle-brain/)
