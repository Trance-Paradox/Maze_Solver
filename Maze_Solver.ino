#include <Arduino.h>
#include "Motor.h"
#include <EEPROM.h>

String directions;

Motor L_motor(7, 8, 9);
Motor R_motor(4, 5, 6);

void turnLeft()
{
    directions.concat('L');
    L_motor.backward();
    R_motor.forward();
    L_motor.setSpeed(200);
    R_motor.setSpeed(200);

    while (!digitalRead(11))
        ;

    L_motor.stop();
    R_motor.stop();
}

void turnRight()
{
    directions.concat('R');
    L_motor.forward();
    R_motor.backward();
    L_motor.setSpeed(200);
    R_motor.setSpeed(200);

    while (!digitalRead(11))
        ;

    L_motor.stop();
    R_motor.stop();
}

void turnBack()
{
    directions.concat('B');
    L_motor.backward();
    R_motor.forward();
    L_motor.setSpeed(200);
    R_motor.setSpeed(200);

    while (!digitalRead(11))
        ;

    L_motor.stop();
    R_motor.stop();
}

void setup()
{
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(10, INPUT);
    pinMode(11, INPUT);

    L_motor.setSpeed(255);
    R_motor.setSpeed(255);
}

void loop()
{
    int ir_left = digitalRead(2);
    int ir_right = digitalRead(3);

    int ir_front[] = {digitalRead(10), digitalRead(11), digitalRead(12)};

    if (ir_left == ir_right == ir_front[0] == ir_front[1] == ir_front[2] == 0)
        turnBack();

    else if (ir_left)
        turnLeft();

    else if (ir_front[0] == ir_front[2])
    {
        L_motor.forward();
        R_motor.forward();
        L_motor.setSpeed(256);
        R_motor.setSpeed(256);
    }

    else if (ir_front[0] == ir_front[1])
    {
        L_motor.forward();
        R_motor.forward();
        L_motor.setSpeed(200);
        R_motor.setSpeed(256);
    }

    else if (ir_front[1] == ir_front[2])
    {
        L_motor.forward();
        R_motor.backward();
        L_motor.setSpeed(256);
        R_motor.setSpeed(200);
    }

    else if (ir_right)
        turnRight();
}
