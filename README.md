# Sun Chaser
A semi-autonomous robot that aims to fully optimize the power of renewable solar energy with a double axis solar tracker and two robust DC motor wheels. This project was made in 24 hours as part of Cornell's 2023 Makeathon and won the Best Hardware Award.

<img src=https://user-images.githubusercontent.com/41922343/227791455-e153e543-f78e-4998-8be7-5f0e63a6b044.jpg width=67% height=67%>

## About 
This robot is built using an Arduino Uno, an H-Bridge motor driver, two DC hobby motors, two positional servos, four light detecting resistors, and a joystick. All parts were provided from Cornell's Maker Club Lab. Its theoretical functionality can be applied in space travel for designing extraplanetary rovers. 

For a more detailed overview of the project, check out the [project presentation](Project%20Sun%20Chaser.pdf)


[![Short Demo Video](https://user-images.githubusercontent.com/41922343/228394081-40f556b8-373a-493e-9413-f3f3e9debd68.png)](https://youtu.be/q-6LHwicius "Sun Chaser Mini Demo - Click to Watch!")
![OneZero Trailer - Hackathon Submission](https://user-images.githubusercontent.com/41922343/228394420-56f4c4ee-0f41-4389-8619-94380013f57e.png "Sun Chaser Trailer")

## Design
Annotated photos of the final design of the robot. 
![Screenshot 2023-03-28 202149](https://user-images.githubusercontent.com/41922343/228395380-cb654a45-f27f-42d8-867e-8cb29363f39f.png)

## Code
Refer to the [Arduino code](solar%20chaser.ino) included in this repository. Code is split between the two functions corresponding to the two main abilities of Sun Chaser. motorControl() utilizes mapping from the joystick analog values to the dc motors drive values. solarTrack() calculates the average amount of light on each side with photoresistors and utilizes servos to adjust so that each side has a similar amount of light 

## Circuit Diagram
![Screenshot 2023-03-26 115329](https://user-images.githubusercontent.com/41922343/228395434-bcabefa7-7236-4e49-a32e-33e98bd0d3bb.png)
