#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>


int LerVoz()
{
	pid_t pid;
	int x;
	pid = fork();
	x = getpid();
	printf("inicio\n");
	if(pid == 0)
	{
		printf("filho %d\n", x);
		char line[81], character;                              
		int c;                                                
		c = 0;  
		int a;
		do                                                      
		{       
			a = system("sudo tail /var/log/syslog"); 
			printf("%d",a);                                           
			character = getchar();                            
			line[c]   = character;  
			if(c>10)
				break;
			c++;                                              
		}while(character != '\n');                                
		c = c - 1;                                              
		line[c] = '\0'; 
		printf("\n%s\n", line);                                         
		exit(0);
	}else
	{
	signal(SIGINT, SIG_IGN);
	printf("pai %d\n", x);
	
	sleep(5);
	kill(0,SIGINT);
	}
	
	

	return 0;
}


int main()
{
	int i=0;
	//while(i<2)
	{
		LerVoz();
		i++;
	}
	
	
	return 0;
}
