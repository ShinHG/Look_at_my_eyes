#ifndef DCMOTOR_H
#define DCMOTOR_H

#define STOP 4 // BCM_GPIO 23
#define DIRECTION 5 // BCM_GPIO 24
#define SIGNAL 6 

int kbhit(void);
int getch(void);
int Motor_Control(char state, int time);
int Motor_init();

#endif
