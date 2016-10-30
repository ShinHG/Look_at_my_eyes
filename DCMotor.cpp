#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <termios.h>

#include <unistd.h>
#include <fcntl.h>

#define STOP 4 // BCM_GPIO 23
#define DIRECTION 5 // BCM_GPIO 24
#define SIGNAL 6 

int kbhit(void);
int getch(void);
char buff = 'p';

int Motor_Control(char state, int time){
		switch(state){
			case 'r':
				printf("right\n");
				softPwmWrite(SIGNAL,255);
				digitalWrite(DIRECTION,1);	
				digitalWrite(STOP,0);
				delay(time);
				printf("finish delay\n");
				break;
			case 'l':
				printf("left\n");
				softPwmWrite(SIGNAL,255);
				digitalWrite(DIRECTION,0);
				digitalWrite(STOP, 0);				
				delay(time);
				printf("finish delay\n");
				break;
			case 'p':
				printf("pause\n");
				digitalWrite(STOP, 1);
				delay(time);
				printf("finish delay\n");
				break;
			
			}
	return 0;	
}

int Motor_init(){
	if(wiringPiSetup() == -1) {
		return 1;
	}
	pinMode(STOP, OUTPUT);
	pinMode(DIRECTION, OUTPUT);
	pinMode(SIGNAL, OUTPUT);

	digitalWrite(STOP,0);
	digitalWrite(DIRECTION,0);
	softPwmCreate(SIGNAL,0,255);
	return 0;
}

int getch(void)
{
    struct termios oldt,
    newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}

int kbhit(void)
{
   struct termios oldt, newt;
   int ch;
   int oldf;
 
   tcgetattr(STDIN_FILENO, &oldt);
   newt = oldt;
   newt.c_lflag &= ~(ICANON | ECHO);
   tcsetattr(STDIN_FILENO, TCSANOW, &newt);
   oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
   fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
   ch = getchar();
 
   tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
   fcntl(STDIN_FILENO, F_SETFL, oldf);
 
   if(ch != EOF)
   {
      ungetc(ch, stdin);
      return 1;
   }
 
   return 0;
}

