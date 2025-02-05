/*
MIT License

Copyright (c) 2025 Breadboard-Engineers

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial bt(9,10); // RX, TX
char data;

  AF_DCMotor M1(1);
  AF_DCMotor M2(2);
  AF_DCMotor M3(3);
  AF_DCMotor M4(4);

void setup() 
{
  bt.begin(9600);
}

void loop() 
{
  if(bt.available()>0)
  {
    data = bt.read();

    stop(); // for stopping the motors initially

    switch(data)
    {
      case 'F':
      {
        Fw(); // for Forward
        break;
      }
      case 'B':
      {
        Bw(); // for Backward
        break;
      }
      case 'L':
      {
        Lf(); // for Left
        break;
      }
      case 'R':
      {
        Rt(); // for Right
        break;
      }
    }
  }

}

void Fw() // for Forward
{
       M1.setSpeed(255);
        M1.run(FORWARD);

        M2.setSpeed(255);
        M2.run(FORWARD);

        M3.setSpeed(255);
        M3.run(FORWARD);
        
        M4.setSpeed(255);
        M4.run(FORWARD);
        
}

void Bw() // for Backward
{
        M1.setSpeed(255);
        M1.run(BACKWARD);

        M2.setSpeed(255);
        M2.run(BACKWARD);

        M3.setSpeed(255);
        M3.run(BACKWARD);

        M4.setSpeed(255);
        M4.run(BACKWARD);
        
}

void Lf() // for Left
{
        M1.setSpeed(255);
        M1.run(BACKWARD);

        M2.setSpeed(255);
        M2.run(BACKWARD);

        M3.setSpeed(255);
        M3.run(FORWARD);

        M4.setSpeed(255);
        M4.run(FORWARD); 
        
}

void Rt() // for Right
{
        M1.setSpeed(255);
        M1.run(FORWARD);

        M2.setSpeed(255);
        M2.run(FORWARD);

        M3.setSpeed(255);
        M3.run(BACKWARD);

        M4.setSpeed(255);
        M4.run(BACKWARD);
        
}

void stop() // for Stop
{
        M1.run(RELEASE); 
        M2.run(RELEASE);
        M3.run(RELEASE);
        M4.run(RELEASE);
}