#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{	
	int i=0, pid_filho; 
	for(i=0; i<3; i++)
	{
		pid_filho = fork();
		if(pid_filho == 0)
		{
			printf("Filho %d\n, Pid %d\n",i+1, (int) getpid() );
			return -1;//return para cancelar a execução nao nao retornar a linha 11, criando um novo filho
		}	
		else
		{
			wait(NULL);
		}
	}		
return 0;
}