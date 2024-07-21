# Arduino Car

The car currently uses Arduino Uno board.
The main goal of this project is to mimic an actual car using RTOS.

## Motor
This car currently has two motors, essentially like a front wheel or rear wheel drive.
The motors are connected to a motor driver module that accepts PWM and direction input.

## PWN signal
I will be using the clock on the ATmega328P to generate the PWN signal.
The two pins that will be used to output the signal are PD5 and PD6.
Table below shows how they are represented in different context

| label on chip | label for clock output | Arduino pin label |
| --- | --- | ---|
| PD5 | OC0B | D5 |
| PD6 | OC0A | D6 |

Due to the nature of motor, I decided that Fast PWM mode is best suited to drive the motors.
The output must be cleared at compare match and set at bottom
With this design, the OCRnx value will directly correspond with the speed the motor is turning: 0 being not turning and 0xFF at the highest.
