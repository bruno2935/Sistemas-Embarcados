
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc,const char * argv[])
{
	int fp;
	char string[]="sem saber da hora iremos procurar tudo o que tiver \n a nao ser que viermos";
	fp=open("ola_mundo.txt",O_RDWR | O_CREAT, S_IRWXU);
		write(fp,string,sizeof(string)-1);
	close(fp);
return 0;
}
