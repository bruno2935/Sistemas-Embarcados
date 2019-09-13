ls
1. Crie um código em C para gerar três processos-filho usando o `fork()`.
```C
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
```

2. Crie um código em C que recebe o nome de diversos comandos pelos argumentos de entrada (`argc` e `*argv[]`), e executa cada um sequencialmente usando `system()`. Por exemplo, considerando que o código criado recebeu o nome de 'serial_system', e que ele foi executado na pasta '/Sistemas_Embarcados/Code/06_Processos', que contem diversos arquivos:

```bash
$ ./serial_system pwd echo ls echo cal
$ ~/Sistemas_Embarcados/Code/06_Processos
$
$ Ex1.c    Ex2b.c   Ex4.c   Ex6.c
$ Ex2a.c   Ex3.c    Ex5.c   serial_system
$
$     Março 2017
$ Do Se Te Qu Qu Se Sá
$           1  2  3  4
$  5  6  7  8  9 10 11
$ 12 13 14 15 16 17 18
$ 19 20 21 22 23 24 25
$ 26 27 28 29 30 31
```
```C
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int i=0;
	for(i=1;i<argc;i++)
	{
		printf("%d\n",argv[i]);
		system(argv[i]);
	}
}
```


3. Crie um código em C que recebe o nome de diversos comandos pelos argumentos de entrada (`argc` e `*argv[]`), e executa cada um usando `fork()` e `exec()`.
```C
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char **argv)
{
	int i;
	char * ls_args[] = {NULL, NULL}; //suponho apenas um argumento, com 2 teriamos Char * ls_args[] = {NULL, NULL, NULL, NULL};
	for(i=1;i<argc;i++)
	{
		if(fork()==0) //processo filho criado
		{
		printf("%s:\n",argv[i]);
		ls_args[0] = argv[i];
		execvp(ls_args[0], ls_args); //
		printf("Houve erro na chamada a %s\n",argv[i]);
		exit(-1);
		}
		else
		wait(NULL); //espera o processo filho terminar a execução
	}
return 0;
}
```



4. Crie um código em C que gera três processos-filho usando o `fork()`, e que cada processo-filho chama a seguinte função uma vez:

```C
int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}
```
```C
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>



int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}

int main(int argc, char *argv[])
{	
	int i=0, pid_filho; 
	for(i=0; i<3; i++)
	{
		pid_filho = fork();
		if(pid_filho == 0)
		{	
			Incrementa_Variavel_Global(getpid());//incrementa a variavel global 
			return -1;//return para cancelar a execução nao nao retornar a linha 11, criando um novo filho
		}	
		else
		{
			wait(NULL);
		}
	}		
return 0;
}
```

(Repare que a função `Incrementa_Variavel_Global()` recebe como entrada o ID do processo que a chamou.) Responda: a variável global `v_global` foi compartilhada por todos os processos-filho, ou cada processo enxergou um valor diferente para esta variável?

5. Repita a questão anterior, mas desta vez faça com que o processo-pai também chame a função `Incrementa_Variavel_Global()`. Responda: a variável global `v_global` foi compartilhada por todos os processos-filho e o processo-pai, ou cada processo enxergou um valor diferente para esta variável?
```C
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>



int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}

int main(int argc, char *argv[])
{	
	int i=0, pid_filho; 
	for(i=0; i<3; i++)
	{
		pid_filho = fork();
		if(pid_filho == 0)
		{	
			Incrementa_Variavel_Global(getpid());//incrementa a variavel global 
			return -1;//return para cancelar a execução nao nao retornar a linha 11, criando um novo filho
		}	
		else
		{
			Incrementa_Variavel_Global(getpid());//incrementa a variavel global 
			wait(NULL);
		}
	}		
return 0;
}
```