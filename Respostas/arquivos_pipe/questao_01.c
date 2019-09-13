#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define N 20

int main()
{
	int i=0,a=0;
	char buffer_saida[N];
	char buffer_entrada[N];
	int pid;
	int fd[2];
	pipe(fd); //cria o mecanismo pipe com fd[0] para leitura, fd[1] para escrita
	pid= fork(); //cria o processo filho
	//processo pai
	if(pid !=0)
	{
		while(1)
		{
			i++;
			sprintf(buffer_saida, "%d", i);
			write(fd[1], buffer_saida, N);
			sleep(1);
			if(i==11)
				{return -1;}
		}
	}
	//processo filho
	else
	{
		while(1)
		{	
			sleep(1);
			read(fd[0], buffer_entrada, N);
			a=atoi(buffer_entrada);
			if(a <11)
			{
				printf("%d\n", a);
			}else
			{
			return -1;
			}

			wait(NULL);
			}
	}


return 0;
}