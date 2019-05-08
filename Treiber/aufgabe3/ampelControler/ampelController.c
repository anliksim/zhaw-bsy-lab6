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
	const char *parDev = "/dev/ParDev";
    char lights[1];                         // byte to   ampel (lights)
    char button[1];                         // byte from ampel (button)

    // open device and initialize ampel
    // your code
    ...

    // ampel loop
    
	while (1) {
        // your code
        ...
    }

}
