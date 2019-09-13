#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* le_arq_texto(char *nome_arquivo)
{
		


	FILE *fl;
	char *nome = (char *) malloc(200*sizeof(char));
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

int main(int argc,const char * argv[])
{

	char *texto = (char *) malloc(200*sizeof(char)); 
	strncpy (texto, argv[1], sizeof(argv[1])*4);	
	printf("%s \n", le_arq_texto(texto));	
	free(texto);
return 0;

}