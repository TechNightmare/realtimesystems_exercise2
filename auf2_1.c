#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define CHILD 0
#define FAILURE -1

void exithandler() { printf("Goodbye %s \n", getlogin());}

int main()
{

	int p = fork();
	if(p == CHILD)
	{
		sleep(1);
		printf("PID: %u\n", getpid());
		printf("PPID: %u\n", getppid());
	}

	else if(p > CHILD)
		atexit(exithandler);
	else
		perror("Fork failed.\n");
	
	return EXIT_SUCCESS;
}