#include <stdio.h>
#include "headers/motors.h"

int main(void)
{
	printf("Welcome at WheelRobot App. \nCreated by Marcin Kierinkiewicz 2021\n");
	motors_init();
	
	printf("Program stoped.\n");

	return 0;
}
