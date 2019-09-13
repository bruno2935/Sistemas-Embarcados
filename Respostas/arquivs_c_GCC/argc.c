#include <stdio.h>
int main( int argc, char *argv[ ] )
{
	int i=0;
	printf("Ola ");
	for(i=1;i<argc;i++)
	{	
		printf("%s ", argv[i]);
	}	  
 	printf("\nNúmero de entradas= %d\n", argc);
 return 0;
}

