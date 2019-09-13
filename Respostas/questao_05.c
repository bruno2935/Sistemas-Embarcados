#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>

#define N 20


void int_trata_alarme(int sig)
{
	system("ps");
}

void int_quit(int sig)
{
	printf("Processo terminado!\n");
	exit(1);
}


int main()
{	
		signal(SIGALRM,int_trata_alarme);
		signal(SIGINT,int_quit);
		while(1)
		{
			alarm(1);
	    }

return 0;
}