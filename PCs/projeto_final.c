
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include<json-c/json.h>
#include <string.h>
#include <stdint.h>
#include<json-c/json.h>





volatile int varCompartilhada=0;

static pthread_mutex_t mutexLock;



struct json_struct
{
  int number;
  char name[50];       // Declaring an array will allocate the specified
};


struct json_struct dados_json()
{
	struct json_struct js;
	FILE *fp;
	char buffer[1024]; 
	//static char buffer2[1024];
	struct json_object *parsed_json;
	struct json_object *message;
	struct json_object *text;
	struct json_object *chat;
	struct json_object *message_id;

	fp = fopen("test2.json","r");
//	if(fp == NULL) // testa se o arquivo foi aberto com sucesso
//	 {
//	 printf("\n\nImpossivel abrir o arquivo!\n\n");
//	 return 0
//	 }


	fread(buffer, 1024, 1, fp);
	fclose(fp);

	parsed_json = json_tokener_parse(buffer);
	json_object_object_get_ex(parsed_json, "message", &message);

	json_object_object_get_ex(message, "message_id", &message_id);
	json_object_object_get_ex(message, "text", &text);
	
	strcpy(js.name,json_object_get_string(text));
	js.number=json_object_get_int(message_id);
return js;
}




// Função que incrementa o Contador
void* bot_data_RT (void *arg)
{


//	printf("text %s - message_id %d\n",json_dados.name,json_dados.number);
	system("wget -r -P /home/bruno/codigos_exemplos/  https://api.telegram.org/bot961579878:AAG4cVhRDowO13ZJ1vRm-3DHSiukfzQN2U8/getUpdates");
	system("tail -n1 /home/bruno/codigos_exemplos/api.telegram.org/bot961579878:AAG4cVhRDowO13ZJ1vRm-3DHSiukfzQN2U8/getUpdates > test.json");
	system("sed '1s/^/{/' test.json > test2.json");




struct json_struct json_dados;
  char linha2[200],temp[]="/temp",foto[]="/retrato",bomba[]="/agua",comandos[]="/comandos";
  int i=8000,msg_id1=0,msg_id2=1;

  json_dados=dados_json();
  msg_id2=json_dados.number;
  printf("id é %d\n", msg_id2 );
while(1)
	{	
	printf("Baixando Site\n");
	system("wget -r -P /home/bruno/codigos_exemplos/  https://api.telegram.org/bot961579878:AAG4cVhRDowO13ZJ1vRm-3DHSiukfzQN2U8/getUpdates");
	system("tail -n1 /home/bruno/codigos_exemplos/api.telegram.org/bot961579878:AAG4cVhRDowO13ZJ1vRm-3DHSiukfzQN2U8/getUpdates > test.json");
	system("sed '1s/^/{/' test.json > test2.json");


	json_dados=dados_json();
	msg_id1=json_dados.number;
	if(msg_id1!=msg_id2)
	{
	    	printf("Comando recebido do bot\n");
	 		if (strcmp(temp,json_dados.name)==0)
	 		{
	 			
	 			printf("Mande a temperatura\n");
	 			sprintf (linha2,"curl -s -X POST https://api.telegram.org/bot961579878:AAG4cVhRDowO13ZJ1vRm-3DHSiukfzQN2U8/sendMessage -d chat_id=658446605 -d text='quem é  %d'", varCompartilhada );
	 			system(linha2);
	 		
	 		}
	
	 		if(strcmp(foto,json_dados.name)==0)
	 		{

	 			system("curl -X POST https://api.telegram.org/bot961579878:AAG4cVhRDowO13ZJ1vRm-3DHSiukfzQN2U8/sendPhoto? -F chat_id=658446605 -F photo=@/home/bruno/codigos_exemplos/foto.jpg");

	 		}

	  		if(strcmp(bomba,json_dados.name)==0)
	 		{

	 			system("curl -s -X POST https://api.telegram.org/bot961579878:AAG4cVhRDowO13ZJ1vRm-3DHSiukfzQN2U8/sendMessage -d chat_id=658446605 -d text='Recipiente Cheio'");

	 		}
	 		if(strcmp(comandos,json_dados.name)==0)
	 		{

	 			system("curl -s -X POST https://api.telegram.org/bot961579878:AAG4cVhRDowO13ZJ1vRm-3DHSiukfzQN2U8/sendMessage -d chat_id=658446605 -d text='Ola :) Os comandos da sua DOGhouse são \n /temp: Informa a temperatura da casinha \n /retrato: Tira uma foto do interior da casinha \n /agua: Enche o recipiente de agua do cachorro'");

	 		}
		


	 
	}
	msg_id2=msg_id1;	  
	sleep(2);
   }



	return NULL;
}

// Função que decrementa o Contador
void* DATA_GET (void *arg)
{
	while(1)
	{
		scanf("%d", &varCompartilhada);
		sleep(1);

	}

	return NULL;
}

int main (int argc, char** argv)
{
	pthread_t t0;
	pthread_t t1;

	printf("Este exemplo eh igual ao anterior, exceto pelo uso de um MUTEX\n");
	printf("para evitar a concorrencia entre as threads.\n");
	printf("Execute o codigo varias vezes para ver o valor final de 'varCompartilhada'.\n\n");
	printf("Valor inicial: %d\n", varCompartilhada);
	
	pthread_mutex_init(&mutexLock, NULL);
	pthread_create(&t0, NULL, bot_data_RT, NULL);
	pthread_create(&t1, NULL, DATA_GET, NULL);
	pthread_join(t0, NULL);
	pthread_join(t1, NULL);

	pthread_mutex_destroy(&mutexLock);

	printf("Valor final: %d\n", varCompartilhada);
	return 0;
}