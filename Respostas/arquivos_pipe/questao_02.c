#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define N 100

int main()
{
	int i=0,a=0;
	char buffer_saida[N];
	char buffer_entrada[N];
	int pid_1,pid_2;
	int fd[2];
	pipe(fd); //cria o mecanismo pipe com fd[0] para leitura, fd[1] para escrita
	pid_1= fork(); //cria o processo filho
	//processo pai
	if(pid_1 !=0)
	{

		pid_2= fork();
		//processo pai
		if(pid_2 !=0)
		{	
			sleep(2);
			read(fd[0], buffer_entrada, N);
			printf("FILHO_2: %s\n", buffer_entrada);
			sleep(1);
		    strcpy(buffer_saida,"Os dois se enganam. É a mente dos senhores que se move.");  
			write(fd[1], buffer_saida,N);
			sleep(1);


		}
		//processo filho 2
		else
		{
			sleep(1);
			read(fd[0], buffer_entrada, N);
			printf("FILHO_1: %s\n", buffer_entrada);
			strcpy(buffer_saida,"Não, é o vento que se move.");
			write(fd[1], buffer_saida,N);
			sleep(1);
			read(fd[0], buffer_entrada, N);
			printf("PAI: %s\n", buffer_entrada);

		}
	
	}
	//processo filho 1
	else
	{
		strcpy(buffer_saida," Quando o vento passa, é a bandeira que se move.");
		write(fd[1], buffer_saida,N);
		sleep(3);
		
			

			
	}


return 0;
}