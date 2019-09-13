	1. Crie um programa em C que cria um processo-filho e um pipe de comunicação. Faça com que o processo-pai envie os valores 1, 2, 3, 4, 5, 6, 7, 8, 9 e 10 para o processo-filho, com intervalos de 1 segundo entre cada envio. Depois de o processo-pai enviar o número 10, ele aguarda 1 segundo e termina a execução. O processo-filho escreve na tela cada valor recebido, e quando ele receber o valor 10, ele termina a execução.
```C
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
	//processo pai
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
```



2. Crie um programa em C que cria um processo-filho e um pipe de comunicação. Utilize o pipe para executar a seguinte conversa entre processos:

```
FILHO: Pai, qual é a verdadeira essência da sabedoria?
PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.
FILHO: Mas até uma criança de três anos sabe disso!
PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...
```

```C
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#define N 100
int main()
{
	char buffer_saida[N];
	char buffer_entrada[N];
	int pid;	// PID do processo filho
	int fd[2];	// Descritores do pipe
	pipe(fd);  // 2 endereços, um de leitura, outro de escrita
	pid = fork();
	// Codigo do filho
	if(pid == 0)
	{
		strcpy(buffer_saida,"Pai, qual é a verdadeira essência da sabedoria?");
		write(fd[1], buffer_saida,N);
		sleep(1);
		read(fd[0], buffer_entrada, N);
		printf("PAI: %s\n", buffer_entrada);
		strcpy(buffer_saida,"Mas até uma criança de três anos sabe disso!");
		write(fd[1], buffer_saida,N);
		sleep(1);
		read(fd[0], buffer_entrada, N);
		printf("PAI: %s\n", buffer_entrada);
		

	}
	// Codigo do pai
	else
	{
		read(fd[0], buffer_entrada, N);
		printf("FILHO: %s\n", buffer_entrada);
		strcpy(buffer_saida,"Não façais nada violento, praticai somente aquilo que é justo e equilibrado.");
		write(fd[1], buffer_saida,N);
		sleep(1);
		read(fd[0], buffer_entrada, N);
		printf("FILHO: %s\n", buffer_entrada);
		strcpy(buffer_saida,"Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...");
		write(fd[1], buffer_saida,N);	
	}
	return 0;
}
```


Neste exercício, quem recebe a mensagem via pipe é quem as escreve no terminal.

3. Crie um programa em C que cria dois processos-filhos e um pipe de comunicação. Utilize o pipe para executar a seguinte conversa entre processos:

```
FILHO1: Quando o vento passa, é a bandeira que se move.
FILHO2: Não, é o vento que se move.
PAI: Os dois se enganam. É a mente dos senhores que se move.
```
```C
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
```	

Neste exercício, quem recebe a mensagem via pipe é quem as escreve no terminal.

4. Crie um programa em C que cria um processo-filho e um pipe de comunicação. O processo-filho deverá pedir o nome do usuário, envia-lo para o pai via pipe, e o pai deverá escrever o nome do usuário no terminal.
```C
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
```

5. Utilize o sinal de alarme para chamar a cada segundo o comando `ps` ordenando todos os processos de acordo com o uso da CPU. Ou seja, seu código atualizará a lista de processos a cada segundo. Além disso, o código deverá tratar o sinal do CTRL-C, escrevendo "Processo terminado!" na tela antes de terminar a execução do processo.
```C
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>


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
		sleep(1);
		alarm(1);

return 0;
}
```
