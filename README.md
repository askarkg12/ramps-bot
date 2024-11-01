# RAMPS Bot

RAMPS Bot is an open-source project designed to leverage the popularity of Arduino Mega and RAMPS boards, especially within the 3D printing community. This repository provides firmware that allows for direct manipulation of hardware components, starting with stepper motors. With this project, users can easily build and control robots using widely available components.

Although this repository specifically targets mecanum wheel based robots, it can be easily modified to account for other types of robots.

The codebase is originally built to work with ROS2, however the communications are written in controller agnostic manner.
Please contact me or raise an issue for any questions.

### Prerequisites

- **Arduino Mega** 
- **RAMPS Board**: Tested on 1.6
- **Stepper Motor**: Tested on A4988, but any should work.
