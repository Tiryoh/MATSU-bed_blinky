#include "mbed.h"
#include "USBSerial.h"

#define LED1 P0_29
#define LED2 P0_28
#define LED3 P0_27
#define LED4 P0_26

#define ISP0 P0_4
#define ISP1 P0_16

//USBSerial pc;

BusOut myled(LED1, LED2, LED3, LED4);

//DigitalIn sw1(ISP0);
//DigitalIn sw2(ISP1);

int main() {
    //sw1.mode(PullUp);
    
    myled = 0b0001;
    
    while(1){
        if(myled < 0b1000){
            wait(0.5);
            myled = myled << 1;
        }else{
            while(myled != 0b0001) {
                wait(0.5);
                myled = myled >> 1;
            }
        }
    }
}
