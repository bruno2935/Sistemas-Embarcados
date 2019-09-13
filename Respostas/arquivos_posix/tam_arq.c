#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


long tam_arq_texto(char *nome_arquivo)
{
		
	int fl;
	char tam[200];
	long tamanho;	
	fl=open(nome_arquivo,O_RDWR | O_CREAT, S_IRWXU);

		
		tamanho= read(fl,&tam,sizeof(char)*100);
		close(fl);
	
	
return tamanho;
}

int main()
{
	char arquivo[100];
	long tamanho;
	printf("digite o nome do arquivo: ");
	scanf("%s", arquivo);
	tamanho=tam_arq_texto(arquivo);
	printf("%ld bytes\n", tamanho);	
return 0;
}