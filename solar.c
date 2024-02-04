#include <Servo.h> 

Servo Sg90servo;

#define ldr1 P1_6
#define ldr2 P1_7 

int pos = 90; 
int tolerance = 20; 
   
void setup(){
Sg90servo.attach(4); 
pinMode(ldr1, INPUT); 
pinMode(ldr2, INPUT); 
Sg90servo.write(pos); 
    
delay(1000); 
}

void loop(){      
int val1 = analogRead(ldr1); 
int val2 = analogRead(ldr2); 
      
if((abs(val1 - val2) <= tolerance) || (abs(val2 - val1) <= tolerance)) {

}else {
if(val1 > val2) 
{
pos = pos+1; 
}
if(val1 < val2) 
{
pos = pos-1; 
 }
}
     
if(pos > 180) {pos = 180;} 
if(pos < 0) {pos = 0;} 
Sg90servo.write(pos); 
delay(50);

}