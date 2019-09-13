Para todas as questões, compile-as com o gcc e execute-as via terminal.

1. Crie um "Olá mundo!" em C.
--------------------------------------------------------------------------------------------------
#include<stdio.h>

int main()
{
	printf("hello word!!!\n");

return 0;
}
--------------------------------------------------------------------------------------------------

2. Crie um código em C que pergunta ao usuário o seu nome, e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

--------------------------------------------------------------------------------------------------
#include<stdio.h>

int main()
{
	char nome[10];
	printf("Digite seu nome:");
	scanf("%s", nome);
	printf("Ola eu sou %s\n",nome);

return 0;
}
--------------------------------------------------------------------------------------------------



3. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.

	Digite seu nome:Eu Mesmo
        Ola eu sou eu

(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:

	Digite seu nome:"Eu Mesmo"
	Ola eu sou "Eu
	

(c) Se é usado um pipe. Por exemplo:
```bash

$ echo Eu | ./ola_usuario_1
	Digite seu nome:Ola eu sou Eu
```

(d) Se é usado um pipe com mais de um nome. Por exemplo:

```bash
$ echo Eu Mesmo | ./ola_usuario_1
	/a.out
	Digite seu nome:Ola eu sou Eu

```

(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:

```bash
$ echo "Eu Mesmo" | ./ola_usuario_1
	Digite seu nome:Ola eu sou Eu
```

(f) Se é usado o redirecionamento de arquivo. Por exemplo:
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_1 < ola.txt
        Digite seu nome:Ola eu sou Ola

```

4. Crie um código em C que recebe o nome do usuário como um argumento de entrada (usando as variáveis argc e *argv[]), e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu

#include <stdio.h>
int main( int argc, char *argv[ ] )
{
	int i=0;
	printf("Ola ");
	for(i=1;i<argc;i++)
	{	
		printf("%s ", argv[i]);
	}	  
 	printf("\n");
 return 0;
}


```

5. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.
```bash
$ ./ola_usuario_2 Eu Mesmo
	Ola Eu Mesmo 

```


(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:
```bash
$ ./ola_usuario_2 "Eu Mesmo"
	Ola Eu Mesmo 
```

(c) Se é usado um pipe. Por exemplo:
```bash
$ echo Eu | ./ola_usuario_2
```     Ola

(d) Se é usado um pipe com mais de um nome. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_2
	Ola
```

(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_2
```	Ola

(f) Se é usado o redirecionamento de arquivo. Por exemplo:
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_2 < ola.txt
```     ola

6. Crie um código em C que faz o mesmo que o código da questão 4, e em seguida imprime no terminal quantos valores de entrada foram fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_3':

```bash
$ ./ola_usuario_3 Eu
$ Ola Eu
$ Numero de entradas = 2

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
```

7. Crie um código em C que imprime todos os argumentos de entrada fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_argumentos':

```bash
$ ./ola_argumentos Eu Mesmo e Minha Pessoa
$ Argumentos: Eu Mesmo e Minha Pessoa

#include <stdio.h>
int main( int argc, char *argv[ ] )
{
	int i=0;
	for(i=1;i<argc;i++)
	{	
		printf("%s ", argv[i]);
	}	  
 	printf("\n");
 return 0;
}
```

8. Crie uma função que retorna a quantidade de caracteres em uma string, usando o seguinte protótipo:
`int Num_Caracs(char *string);` Salve-a em um arquivo separado chamado 'num_caracs.c'. Salve o protótipo em um arquivo chamado 'num_caracs.h'. Compile 'num_caracs.c' para gerar o objeto 'num_caracs.o'.

int contaChar(char str[]) {
    int i = 0;

    while(str[i] != 0)
    {
	i++;
    }

    return i;
}
	

9. Re-utilize o objeto criado na questão 8 para criar um código que imprime cada argumento de entrada e a quantidade de caracteres de cada um desses argumentos. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_1':

```bash
$ ./ola_num_caracs_1 Eu Mesmo
$ Argumento: ./ola_num_caracs_1 / Numero de caracteres: 18
$ Argumento: Eu / Numero de caracteres: 2
$ Argumento: Mesmo / Numero de caracteres: 5

#include <stdio.h>


int contaChar(char str[]) {
    int i = 0;

    while(str[i] != 0)
    {
	i++;
    }

    return i;
}

int main()
{ 
	int i=0;
	char nome[100];
	scanf("%s", nome);
	i=contaChar(nome);
	printf("%s / Numero de caracteres: %d ",nome,i);
}







```

10. Crie um Makefile para a questão anterior.

11. Re-utilize o objeto criado na questão 8 para criar um código que imprime o total de caracteres nos argumentos de entrada. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_2':

```bash
$ ./ola_num_caracs_2 Eu Mesmo
$ Total de caracteres de entrada: 25
#include <stdio.h>


int contaChar(char str[]) {
    int i = 0;

    while(str[i] != 0)
    {
	i++;
    }

    return i;
}

int main()
{ 
	int i=0;
	char nome[100];
	scanf("%s", nome);
	i=contaChar(nome);
	printf("%s / Numero de caracteres: %d ",nome,i);
}


```

12. Crie um Makefile para a questão anterior.
