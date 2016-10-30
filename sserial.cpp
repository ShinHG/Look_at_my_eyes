#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <wiringPi.h>
#include <wiringSerial.h>


void Serial_Setup()
{
	int fd;

	char device[]="/dev/ttyAMA0";
	unsigned long baud =9600;

	printf("Raspberry Startup!\n");
	fflush(stdout);
	if((fd = serialOpen(device,baud))<0)
	{
		fprintf(stderr,"Unable to open serial devce: %s\n",strerror(errno));
		exit(1);
	}
	if(wiringPiSetup()==-1){
		fprintf(stdout,"Unable to start wiringPi:%s\n",strerror(errno));
		exit(1);
	}
}

void TX_Serial(char tx){
	int fd;
	unsigned long time=0;
	if(millis()-time>=3000)
	{
		serialPutchar(fd,tx);
		time=millis();
	}
}

char RX_Serial(){
	char rx;
	int fd;
	if(serialDataAvail(fd)){
		rx = serialGetchar(fd);
		printf("%c\n",rx);
	}

	return rx;
}

