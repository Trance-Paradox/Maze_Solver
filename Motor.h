#include <Arduino.h>

#ifdef _Motor_Class_

#else
#define _Motor_Class_
class Motor
{
private:
    int MotorInput_1, MotorInput_2, MotorInput_Speed;
    uint8_t speed;

public:
    Motor(int mi_1, int mi_2, int mi_s)
        : MotorInput_1(mi_1), MotorInput_2(mi_2), MotorInput_Speed(mi_s)
    {
        pinMode(MotorInput_1, OUTPUT);
        pinMode(MotorInput_2, OUTPUT);
        pinMode(MotorInput_Speed, OUTPUT);
    }

    void forward()
    {
        digitalWrite(MotorInput_1, 1);
        digitalWrite(MotorInput_2, 0);
        analogWrite(MotorInput_Speed, speed);
    }

    void backward()
    {
        digitalWrite(MotorInput_1, 1);
        digitalWrite(MotorInput_2, 0);
        analogWrite(MotorInput_Speed, speed);
    }

    void stop()
    {
        digitalWrite(MotorInput_1, 1);
        digitalWrite(MotorInput_2, 0);
        analogWrite(MotorInput_Speed, speed);
    }

    void setSpeed(uint8_t spd)
    {
        speed = spd;
    }

    uint8_t retSpeed()
    {
        return speed;
    }
};

#endif