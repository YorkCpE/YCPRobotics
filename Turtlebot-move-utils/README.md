# ros-utilities
A small library of movement and location utility functions for ROS/Turtlebot.

**Future implementations:**
* Move using odometry
* Camera feedback
* Tele-op mode with optional joystick mode

##Note:
To use this library correctly, a few changes must be made to your package's CMakeLists.txt file;
Add the following lines of code: 
     `find_package(catkin REQUIRED COMPONENTS roscpp geometry_msgs actionlib actionlib_msgs)`
     `generate_messages( DEPENDENCIES std_msgs actionlib_msgs )`



##Function Documentation:
###TurtlebotMover(ros::Publisher publisher)
Constructor. Creates a new TurtlebotMover object.<br/>
**Param:** `ros::Publisher publisher`: a publisher object to publish `geometry_msgs::Twist` messages.

###void moveForSeconds(int numSeconds, float linearVelocity, float angularVelocity)
Move along the vector defined by the specified linear and angular velocities for the specified number of seconds.<br/>
**Param:** `int numSeconds`: the number of seconds to move for.<br/>
**Param:** `float linearVelocity`: the linear velocity at which to move, represented as a decimal between [-1.0f, 1.0f] inclusive.<br/>
**Param:** `float angularVelocity`: the angular velocity at which to move, represented as a decimal between [-1.0f, 1.0f] inclusive.<br/>

###bool moveMeters(float dx, float dy)
Move the specified distance in the X and Y directions in Meters. Moves in a straight line to the destination point.<br/>
**Param:** `float dx`: the number of meters to move in the X direction.<br/>
**Param:** `float dy`: the number of meters to move in the Y direction.<br/>

###bool moveCentimeters(float dx, float dy)
Move the specified distance in the X and Y directions in Centimeters. Moves in a straight line to the destination point.<br/>
**Param:** `float dx`: the number of centimeters to move in the X direction.<br/>
**Param:** `float dy`: the number of centimeters to move in the Y direction.<br/>