1. Crie um programa em C que cria uma thread, e faça com que o programa principal envie os valores 1, 2, 3, 4, 5, 6, 7, 8, 9 e 10 para a thread, com intervalos de 1 segundo entre cada envio. Depois de o programa principal enviar o número 10, ele aguarda 1 segundo e termina a execução. A thread escreve na tela cada valor recebido, e quando ela receber o valor 10, ela termina a execução.
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>


volatile int cnt=0,a=0;
static pthread_mutex_t mutexLock;


void* print_number(void *argumento)
{
	
	while(cnt<10)
	{
		if(a==0)
		{
			pthread_mutex_lock(&mutexLock);
				printf("%d\n", cnt);
				a=1;
			pthread_mutex_unlock(&mutexLock);
		}	
	}
	pthread_exit(0);
	
	
		
return NULL;
}

int main()
{
	int i=0;
	pthread_t thread_id1;
	pthread_mutex_init(&mutexLock, NULL); //inicia mutex
	pthread_create (&thread_id1, NULL, print_number, NULL);
 
   	for(i=0;i<10;i++)
    {	
    	sleep(1);
       	pthread_mutex_lock(&mutexLock);
    	cnt++;
    	a=0;
    	pthread_mutex_unlock(&mutexLock);

    }	
 	pthread_join(thread_id1, NULL);
	pthread_mutex_destroy(&mutexLock); //inicia mutex
	return -1;

return 0;
}
```


2. Crie um programa em C que preenche o vetor `long int v[50000]` completamente com valores aleatórios (use a função `random()`), e que procura o valor máximo do vetor por dois métodos:

(a) Pela busca completa no vetor `v[]`;

(b) Separando o vetor em 4 partes, e usando 4 threads para cada uma encontrar o máximo de cada parte. Ao final das threads, o programa principal compara o resultado das quatro threads para definir o máximo do vetor.

Ao final do programa principal, compare os resultados obtidos pelos dois métodos.

3. Repita o exercício anterior, mas calcule a média do vetor ao invés do valor máximo.

4. Repita o exercício anterior, mas calcule a variância do vetor ao invés da média.

# Questões extra somente para estudo

5. Crie um programa em C que preenche matrizes `long int A[60][60]` e `long int B[60][60]` completamente com valores aleatórios (use a função `random()`), e que calcula a soma das duas matrizes por dois métodos:

(a) De forma sequencial;

(b) De forma paralela.

Ao final do programa principal, compare os resultados obtidos pelos dois métodos.

6. Repita o exercício anterior, mas calcule o produto matricial A*B.

7. Repita o exercício anterior, mas calcule o produto da matriz `long int A[60][60]` por um escalar `long int x`.
