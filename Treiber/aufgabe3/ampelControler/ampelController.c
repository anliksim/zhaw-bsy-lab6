/******************************************************************************
* Ampel Controller
* Author:	M. Thaler
* File:		ampelController.c
* Version:	5/2016	M. Thaler
******************************************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#define OFF    0x80
#define RED    0x81
#define YELLOW 0x82
#define GREEN  0x84

int main(int argc, char* argv[]) {
	int res = 0;
	int MyDev, i;
	const char *parDev = "/dev/ParDev";
    char lights[1];                         // byte to   ampel (lights)
    char button[1];                         // byte from ampel (button)

    char dev[50];
    char errStr[50];
    // open device and initialize ampel
    strcpy(dev, parDev);
    printf("\n--> device: %s\n", dev);

    MyDev = open(dev, O_RDWR);
    if (MyDev < 1) {
        sprintf(errStr, "\n** Cannot open device %s", dev);
        perror(errStr);
        exit(-1);
    }

    lights[0] = RED;

    // ampel loop
    while (1) {
        res = write(MyDev, lights, 1);
        res = read(MyDev,button,1);
        if(button[0] & 0x40){
            lights[0] = GREEN;
            res = write(MyDev, lights, 1);
            sleep(5);

            lights[0] = YELLOW;
            res = write(MyDev, lights, 1);
            sleep(3);

            for(i = 0; i < 3; i++){
                lights[0] = OFF;
                res = write(MyDev, lights, 1);
                sleep(1);
                lights[0] = YELLOW;
                res = write(MyDev, lights, 1);
                sleep(1);
            }
            lights[0] = RED;
            res = write(MyDev, lights, 1);
            sleep(5);
        }
    }
}
