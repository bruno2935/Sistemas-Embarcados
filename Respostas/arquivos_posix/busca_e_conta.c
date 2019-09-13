#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>



char* le_arq_texto(char *nome_arquivo)
{
		



	int fl;
	char *nome = (char *) malloc(200*sizeof(char));
	
	fl=open(nome_arquivo,O_RDWR | O_CREAT, S_IRWXU);


		for(i=0;nome[i];i++)
		{


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