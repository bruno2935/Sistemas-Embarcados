#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int i=0;
	for(i=1;i<argc;i++)
	{
		printf("%d\n",argv[i]);
		system(argv[i]);
	}
}