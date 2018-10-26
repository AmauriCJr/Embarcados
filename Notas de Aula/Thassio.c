#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void InterrompeLeitura (int signum)
{
	
}


int LerVoz()
{
	pid_t pid;
	signal(SIGALRM, InterrompeLeitura);
	pid = fork();
	if(pid == 0)
	{
		system("snips-watch -vvv");
	}else 
	printf("caralho\n");
	alarm(5);
	pause();
	return 0;
}


int main()
{
	LerVoz();
	
	
	
	return 0;
}
