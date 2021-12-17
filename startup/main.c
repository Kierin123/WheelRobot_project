#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

static char *command[3] = {"sudo", "wheelrobot", NULL};

int main(void)
{
	printf("Welcome at WheelRobot App. \nCreated by Marcin Kierinkiewicz 2021\n");

	pid_t pid;

	pid = fork();

	if (pid < 0)
	{
		printf("Cannot create process. \n");
	}
	else if (pid == 0)
	{
		execvp(command[0], command);
	}
	else
	{
		
	}

	printf("Program stoped.\n");

	return 0;
}
