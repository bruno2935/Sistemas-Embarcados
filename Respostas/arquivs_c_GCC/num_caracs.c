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
