Para todas as questões, utilize as funções da norma POSIX (`open()`, `close()`, `write()`, `read()` e `lseek()`). Compile os códigos com o gcc e execute-os via terminal.

1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

```c

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

```

2. Crie um código em C que pergunta ao usuário seu nome e sua idade, e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Digite a sua idade: 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```
```C
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
		write(fp, &id,sizeof(char));		
		write(fp, "\n",1);			
	close(fp);
	

return 0;
}
```



3. Crie um código em C que recebe o nome do usuário e e sua idade como argumentos de entrada (usando as variáveis `argc` e `*argv[]`), e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

```c
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
        	write(fp, &(nome[i]), 1);
			
		}			
		write(fp, "\nIdade: ", 7);
		for(i=0;argv[2][i];i++)
		{
        	write(fp, &(argv[2][i]), 1);

		}	

	close(fp);
	

return 0;
}
```


4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


long tam_arq_texto(char *nome_arquivo)
{
		
	int fl;
	char tam[200];
	long tamanho;	
	fl=open(nome_arquivo,O_RDWR | O_CREAT, S_IRWXU);

		
		tamanho= read(fl,&tam,sizeof(char)*100);
		close(fl);
	
	
return tamanho;
}

int main()
{
	char arquivo[100];
	long tamanho;
	printf("digite o nome do arquivo: ");
	scanf("%s", arquivo);
	tamanho=tam_arq_texto(arquivo);
	printf("%ld bytes\n", tamanho);	
return 0;
}
```

5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: `char* le_arq_texto(char *nome_arquivo);` Repare que o conteúdo do arquivo é armazenado em um vetor interno à função, e o endereço do vetor é retornado ao final. (Se você alocar este vetor dinamicamente, lembre-se de liberar a memória dele quando acabar o seu uso.) Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.
```C
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
```

6. Crie um código em C que copia a funcionalidade básica do comando `cat`: escrever o conteúdo de um arquivo-texto no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'cat_falsificado':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./cat_falsificado ola.txt
$ Ola mundo cruel! Ola universo ingrato!
```
```C
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
	

		read (fl,&nome[0], 100*sizeof(char));

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
```

7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.
```
