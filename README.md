# Cloudie - 5-DOF Robotic Arm
<img width="900" height="675" alt="image" src="https://github.com/user-attachments/assets/f8bddcc9-bdf4-4dae-80fe-42dd19981371" />

## Overview
Cloudie is a robot arm with five degrees of freedom that I created from scratch (with an overall construction inspiration from MeArm) during one of my university internships in 2016. 
Its closed-kinematic-chain architecture provides several advantages over open-chain designs - most notably higher load capacity and improved rigidity.

A key design choice was to place four of the six drives on the base, significantly reducing the mass of the moving arm. This leads to:
- higher positioning precision,
- lower inertia,
- reduced mechanical stress on the structure.

# What Cloudie Is Made Of?
Cloudie is built from a combination of 3D-printed components, servos, a DC motor with encoder, and a collection of miscellaneous parts. Its heart is the Husarion's Core2 board.

Precise List:
- 4 x TowerPro MG995 servos
- 1 TowerPro MG90S servo
- 1 DC motor with encoder
- 1 GT2 timing beltbearing
- 2 x 6000-2RS bearing
- Husarion CORE2
- 3D printed parts
- M3 screws, washers and nuts, servo screws
- several ASG BBs for the base 

# Pics


# Clips


# Inversed kinematics calculations
The inverse kinematics of the manipulator was calculated manually based on the geometric relationships between its joints and connectors. These calculations allowed for the precise determination of the joint angles required to place the gripper in the desired position in space. I derived the equations based on the previously designed arm components and its complex structure. As a result, the manipulator can reach target points and follow predetermined trajectories.
The diagrams and calculations are presented below. Each diagram shows one cast of the manipulator (or part thereof).

## Part I calcs


## Part II calcs


## Cleaned up calculations and results


# Control and movement
I have created three ways to control Cloudie: separate, rectilinear, and coordinates movements. Each of them allows for a different type of motion, depending on needs. Originally, the manipulator control was designed to work via the Internet – through the HusarionCloud solution. Therefore, each original software folder contains both the code itself and a simple HTML page of the user interface used to operate the manipulator. 

## Separate movement 
The manipulator moves each drive individually - each joint separately. Works the same as in an excavator. One key = one joint.


## Rectlinear movement
The manipulator moves only in a straight line – along the imaginary X, Y and Z axes. One key = one axis.


## Coordinates movement  
The manipulator moves directly to predefined Cartesian coordinates. Its zero point (0,0,0) is located at the base of the manipulator - in the middle of the base bearing. The coordinates are entered up front and accepted with a single button press. 


# Controller
The control board used in the manipulator's design is Husarion's Core2. It allows for the simultaneous connection of 5 servo mechanisms and 4 motors with the possibility of control via the Internet.
<img width="913" height="594" alt="image" src="https://github.com/user-attachments/assets/87be5f75-f3d7-4414-ab8b-719667e7c409" />

# Assembly
It’s highly recommended to assemble Cloudie from the base up to the gripper.
Starting elsewhere may cause difficulties when connecting the rotating base to the rest of the arm.
Most of the assembly process is straightforward - except for the gripper, which requires a bit more attention. The illustration below demonstrates the correct assembly method.

<img width="1280" height="663" alt="image" src="https://github.com/user-attachments/assets/07919bcb-af94-456a-8385-c1068d318844" />
<img width="1280" height="805" alt="image" src="https://github.com/user-attachments/assets/397a2348-c1c7-4327-8178-50cc18ade308" />

Once the gripper is installed, the remaining steps simply involve attaching each segment progressively from base to end-effector.

# Wiring
Thanks to the design of the CORE2 control board, all servos and motor are connected directly to the designated connectors. The connections are simple, as shown in the diagram below.
