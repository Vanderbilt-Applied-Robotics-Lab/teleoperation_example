# teleoperation_example
Example of using ROS2 servo to telemanipulate the meca500 robot

## Downloading Code
1. Navigate to examples workspace source folder: `cd ~/workspaces/examples_ws/src`
2. Download code: `git clone https://github.com/Vanderbilt-Applied-Robotics-Lab/teleoperation_example.git`

## Compiling Code
1. Navigate to examples workspace: `cd ~/workspaces/examples_ws`
2. Compile the code: `colcon build`

## Running Code
### Simulated Robot
1. Navigate to the meca500 workspace: `cd ~/workspaces/meca_ws`
2. Source the meca500 workspace: `source install/setup.bash`
3. Launch the meca500 robot: `ros2 launch meca500_bringup moveit.launch.py simulation:=true servo:=true`
4. Move the robot away from a singular position using RVIZ
5. Open a new terminal window
6. Start servo using: `ros2 service call /servo_node/start_servo std_srvs/srv/Trigger "{}"`
7. Connect a game controller to your computer. Make sure to connect to VM and not to host OS if prompted
8. Start the joystick node: `ros2 run joy joy_node`
9. Open a new terminal window
10. Navigate to the examples workspace: `cd ~/workspaces/examples_ws`
11. Source the examples workspace: `source install/setup.bash`
12. Run the code: `ros2 run teleop_example teleop_example`
13. Use the thumbsticks to move robot in translation. Press and hold A to move the robot in rotation  

## Real Robot
1. Connect the meca500 to your computer and turn on power(see quickstart guide)
2. Navigate to the meca500 workspace: `cd ~/workspaces/meca_ws`
3. Source the meca500 workspace: `source install/setup.bash`
4. Launch the meca500 robot: `ros2 launch meca500_bringup moveit.launch.py simulation:=false servo:=true`
5. Wait for robot to release brakes and home. Restart code if robot does not go to home pose.
6. Move the robot away from a singular position using RVIZ
7. Open a new terminal window
8. Start servo using: `ros2 service call /servo_node/start_servo std_srvs/srv/Trigger "{}"`
9. Connect a game controller to your computer. Make sure to connect to VM and not to host OS if prompted
10. Start the joystick node: `ros2 run joy joy_node`
11. Open a new terminal window
12. Navigate to the examples workspace: `cd ~/workspaces/examples_ws`
13. Source the examples workspace: `source install/setup.bash`
14. Run the code: `ros2 run teleop_example teleop_example`
15. Use the thumbsticks to move robot in translation. Press and hold A to move the robot in rotation. Hit the E-Stop if something goes wrong.
16. Shut down the robot (see quickstart guide)  

