Para todas as questões, utilize as funções da biblioteca `stdio.h` de leitura e de escrita em arquivo (`fopen()`, `fclose()`, `fwrite()`, `fread()`, dentre outras). Compile os códigos com o gcc e execute-os via terminal.

1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

```C
#include <stdio.h>

int main(int argc,const char * argv[])
{
	char string[]="ola_mundo";
	FILE *fp;
	fp=fopen("ola_mundo.txt","wb");
		fwrite(string,sizeof(string), 1,fp);cd
	fclose(fp);
	

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

#include <stdio.h>
```C
int main(int argc,const char * argv[])
{
	char string[]="ola_mundo",nome[10];
	int  idade=0;
	FILE *fp;

	fp=fopen("ola_mundo.txt","w");
		printf("Nome:");
		scanf("%s", nome);
		printf("\n");
		printf("Idade:");
		scanf("%d", &idade);

		fprintf(fp,"Nome: %s \n", nome);
		fprintf(fp,"idade: %d \n", idade);
		

		
	fclose(fp);
	

return 0;
}
```

3. Crie um código em C que recebe o nome do usuário e e sua idade como argumentos de entrada (usando as variáveis `argc` e `*argv[]`), e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos

#include <stdio.h>
```C
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
```

4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.
#include <stdio.h>
```C
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

char* le_arq_texto(char *nome_arquivo)
{
		


	FILE *fl;
	char *nome = (char *) malloc(100*sizeof(char));
	char ch;
	int *i;
	fl=fopen(nome_arquivo, "r");
	if(fl != NULL){

		fread (&nome[0], sizeof(double), 100*sizeof(char), fl);

	}else
	{
	printf("Erro na abertura do arquivo");	
	}
	
	free(nome);
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* le_arq_texto(char *nome_arquivo)
{
		


	FILE *fl;
	char *nome = (char *) malloc(200*sizeof(char));
	int *i;
	fl=fopen(nome_arquivo, "r");
	if(fl != NULL){

		fread (&nome[0], sizeof(double), 100*sizeof(char), fl);

	}else
	{
	printf("Erro na abertura do arquivo");	
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

}```

7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.
```
