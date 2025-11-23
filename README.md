# Cloudie - 5-DOF Robotic Arm
<img width="900" height="675" alt="image" src="https://github.com/user-attachments/assets/f8bddcc9-bdf4-4dae-80fe-42dd19981371" />

## Overview
![cloudie-duze png-1](https://github.com/user-attachments/assets/2c171419-3888-4958-bf47-a3eb828ec9be)
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

## Components for printing
Below is a table with the parts that need to be printed in order to build the manipulator. Models, created in OpenSCAD format, can be found in the appropriate folder in the repository. 
<img width="745" height="701" alt="mechnical-parts-list-and-numbers" src="https://github.com/user-attachments/assets/730aea2f-b61b-4117-8252-67007a318f3b" />

# Pics
![0](https://github.com/user-attachments/assets/86db857d-7664-41bd-9906-d18b5772ae7c)
![1](https://github.com/user-attachments/assets/33163579-e58a-49cc-b9ec-eba57051071c)
![2](https://github.com/user-attachments/assets/c5968a5b-eee8-4aea-acf1-afac7f38dceb)
![3](https://github.com/user-attachments/assets/d8eb5daf-e643-4f77-a1ea-4d9c90b1e649)
![4](https://github.com/user-attachments/assets/15d87175-ccaf-487f-aab9-45242907271e)
![5](https://github.com/user-attachments/assets/e97c5975-90fa-442b-afb3-abf8849e1191)
![6](https://github.com/user-attachments/assets/87182e04-19ea-4de5-8405-409f424fa7b5)
![11](https://github.com/user-attachments/assets/077df8d3-920f-4d07-8a38-b14184829b61)
![12](https://github.com/user-attachments/assets/d85aa3f2-2803-4061-b0ee-b727b2f20c7d)
![13](https://github.com/user-attachments/assets/9a75771d-30cf-46dc-88f5-86038b9ae01e)

# Clips
## Separate movement:
[Separate movement](https://youtu.be/uYkaFl4qGg0)

## Rectlinear movement
[Rectlinear movement](https://youtu.be/c3nKy4OTICQ)

## Coordinates movement
[Coordinates movement](https://youtu.be/PuT0RdOZupA)

# Inversed kinematics calculations
The inverse kinematics of the manipulator was calculated manually based on the geometric relationships between its joints and connectors. These calculations allowed for the precise determination of the joint angles required to place the gripper in the desired position in space. I derived the equations based on the previously designed arm components and its complex structure. As a result, the manipulator can reach target points and follow predetermined trajectories.
The diagrams and calculations are presented below. Each diagram shows one cast of the manipulator (or part thereof).

## Calculations - Part I
<img width="1024" height="768" alt="part1-graphics" src="https://github.com/user-attachments/assets/4fa129fe-0469-496e-a0c1-4e1183f2c425" />

## Calculations - Part II 
<img width="1024" height="768" alt="part2-graphics" src="https://github.com/user-attachments/assets/996fffaf-af55-4600-b5a0-e1a52b4a9ec1" />

## Cleaned up calculations and results
<img width="641" height="885" alt="final-cleaned-up-calcs" src="https://github.com/user-attachments/assets/c7ab71da-364b-4ee2-913c-85bf1075e863" />

# Control and movement
I have created three ways to control Cloudie: separate, rectilinear, and coordinates movements. Each of them allows for a different type of motion, depending on needs. Originally, the manipulator control was designed to work via the Internet – through the HusarionCloud solution. Therefore, each original software folder contains both the code itself and a simple HTML page of the user interface used to operate the manipulator. 

## Separate movement 
The manipulator moves each drive individually - each joint separately. Works the same as in an excavator. One key = one joint.
![joints-movement](https://github.com/user-attachments/assets/af7fcb1b-db90-49bb-84ff-ac4e7b85e7ca)

## Rectlinear movement
The manipulator moves only in a straight line – along the imaginary X, Y and Z axes. One key = one axis.
![rectlinear-movement-graph](https://github.com/user-attachments/assets/cc32a5c7-03ad-4555-b334-31a1663d418a)

## Coordinates movement  
The manipulator moves directly to predefined Cartesian coordinates. Its zero point (0,0,0) is located at the base of the manipulator - in the middle of the base bearing. The coordinates are entered up front and accepted with a single button press. 
![coordinates-movement-graph](https://github.com/user-attachments/assets/64d83941-7b51-4c6e-bcdb-31157207feb1)

# Assembly
It’s highly recommended to assemble Cloudie from the base up to the gripper.
Starting elsewhere may cause difficulties when connecting the rotating base to the rest of the arm.
Most of the assembly process is straightforward - except for the gripper, which requires a bit more attention. The illustration below demonstrates the correct assembly method.

<img width="1280" height="663" alt="image" src="https://github.com/user-attachments/assets/07919bcb-af94-456a-8385-c1068d318844" />
<img width="1280" height="805" alt="image" src="https://github.com/user-attachments/assets/397a2348-c1c7-4327-8178-50cc18ade308" />

Once the gripper is installed, the remaining steps simply involve attaching each segment progressively from base to end-effector.

# Wiring
Thanks to the design of the CORE2 control board, all servos and motor are connected directly to the designated connectors. The connections are simple, as shown in the diagram below.
![electrical-wiring](https://github.com/user-attachments/assets/fbb00bad-a28b-4cb9-9a4a-20e6ac5e75b2)

# Controller
The control board used in the manipulator's design is Husarion's Core2. It allows for the simultaneous connection of 5 servo mechanisms and 4 motors with the possibility of control via the Internet.
<img width="913" height="594" alt="image" src="https://github.com/user-attachments/assets/87be5f75-f3d7-4414-ab8b-719667e7c409" />
