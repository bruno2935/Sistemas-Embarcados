
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc,const char * argv[])
{
	char nome[100],id[12]={0x0};
	int  idade=0;
	int fp,i=0;
		printf("Nome:");
		scanf("%s", nome);

		printf("\n");
		printf("Idade:");
		scanf("%d", &idade);
		
	fp=open("ola_mundo.txt",O_RDWR | O_CREAT, S_IRWXU);
		write(fp, "nome: ", 6);

		for(i=0;nome[i];i++)
		{
        	write(fp, &(nome[i]), 1);
			
		}
		sprintf(id, "%d", idade);
		write(fp, "\nIdade: ", 7);
		write(fp, &id,sizeof(id));		
		write(fp, "\n",1);			
	close(fp);
	

return 0;
}
