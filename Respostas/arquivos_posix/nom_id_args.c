
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc,const char * argv[])
{
	char nome[100],id[24]={0x0};
	int  idade=0;
	int fp,i=0;
		
		strncpy (nome, argv[1], sizeof(argv[1])*4);
	
	    fp=open("ola_mundo.txt",O_RDWR | O_CREAT, S_IRWXU);
		write(fp, "nome: ", 6);

		for(i=0;argv[1][i];i++)
		{
        	write(fp, &(argv[1][i]), 1);
			
		}			
		write(fp, "\nIdade: ", 7);
		for(i=0;argv[2][i];i++)
		{
        	write(fp, &(argv[2][i]), 1);

		}	

	close(fp);
	

return 0;
}
