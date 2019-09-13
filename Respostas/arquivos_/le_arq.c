#include <stdio.h>
#include <stdlib.h>

char* le_arq_texto(char *nome_arquivo)
{
		


	FILE *fl;
	char *nome = (char *) malloc(100*sizeof(char));
	char ch;
	int *i;
	fl=fopen(nome_arquivo, "r");
	if(fl != NULL){

		fread (&nome[0], sizeof(double), 100*sizeof(char), fl);

	}else
	{
	printf("Erro na abertura do arquivo");	
	}
	return nome;
}

int main()
{

	char arquivo[100];
	printf("digite o nome do arquivo: ");
	scanf("%s", arquivo);
	
	printf("%s \n", le_arq_texto(arquivo));	
return 0;
}