#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


char* le_arq_texto(char *nome_arquivo)
{
		


	
	char *nome = (char *) malloc(100*sizeof(char));
	char ch;
	int fl,x;
	fl=open(nome_arquivo,O_RDWR | O_CREAT, S_IRWXU);
		read (fl,&nome[0], 100*sizeof(char));

	close(fl);
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