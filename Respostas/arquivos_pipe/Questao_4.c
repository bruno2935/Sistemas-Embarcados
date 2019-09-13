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
	//processo filho
	if(pid ==0)
	{
			
			printf("User name: ");
			scanf(" %[^\n]", buffer_saida);
			write(fd[1], buffer_saida, N);
			exit(-1);


	}
	//processo pai
	else
	{
			
			wait(NULL);
			read(fd[0],buffer_entrada, N);
			printf("Seu nome de usuário é: %s\n", buffer_entrada);
			
	}


return 0;
}