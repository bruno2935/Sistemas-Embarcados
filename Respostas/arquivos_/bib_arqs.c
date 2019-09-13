#include <stdio.h>

long tam_arq_texto(char *nome_arquivo)
{
		
	FILE *fl;
	long tamanho;	
	fl=fopen(nome_arquivo, "r");

	if(fl != NULL){
		fseek(fl, 0, SEEK_END);
		tamanho= ftell(fl);
		fclose(fl);
	}else
	{
	printf("Erro na abertura do arquivo");	
	}
	
return tamanho;
}

int main()
{
return 0;
}
