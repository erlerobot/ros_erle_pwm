cmake_minimum_required(VERSION 2.8.3)
project(ros_erle_pwm)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Declare ROS messages and services
add_message_files(DIRECTORY msg FILES pwm.msg)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

#SET(CMAKE_CXX_FLAGS "fpermissive")
add_definitions ( -fpermissive)

add_executable(ros_erle_pwm_client src/ros_erle_pwm_client.cpp)
target_link_libraries(ros_erle_pwm_client ${catkin_LIBRARIES})
add_dependencies(ros_erle_pwm_client ros_erle_pwm_generate_messages_cpp)

add_executable(ros_erle_pwm_server src/ros_erle_pwm_server.cpp src/GPIO_BBB.cpp src/RCInput.cpp src/RCInput_PRU.cpp src/RCOutput_PRU.cpp src/RC_Channel.cpp src/dsm.cpp src/sbus.cpp)
target_link_libraries(ros_erle_pwm_server ${catkin_LIBRARIES})
add_dependencies(ros_erle_pwm_server ros_erle_pwm_generate_messages_cpp)
