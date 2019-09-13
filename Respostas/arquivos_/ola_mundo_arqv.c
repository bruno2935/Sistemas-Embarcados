#include <stdio.h>

int main(int argc,const char * argv[])
{

	FILE *fp;
	int idade;

	fp=fopen("ola_mundo.txt","w");

		
		fprintf(fp,"Nome: %s \n", argv[1]);
		fprintf(fp,"idade: %s \n",argv[2] );
		

		
	fclose(fp);
	

return 0;
}
