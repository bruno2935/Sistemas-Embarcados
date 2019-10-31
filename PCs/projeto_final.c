
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include<json-c/json.h>
#include <string.h>
#include <stdint.h>





volatile int varCompartilhada=0;

static pthread_mutex_t mutexLock;

struct json_struct
{
  int updat_id;
  int valid;
  char msg[50];       // Declaring an array will allocate the specified

};


struct json_struct dados_json()
{	
	struct json_struct js;
	FILE *fp;
	char buffer[2048];
	struct json_object *parsed_json;
	struct json_object *result;  
	struct json_object *result_n;
	struct json_object *update_id;
	struct json_object *text;
	struct json_object *message;
	size_t i;	

	fp = fopen("/home/bruno/codigos_exemplos/api.telegram.org/bot961579878:AAG4cVhRDowO13ZJ1vRm-3DHSiukfzQN2U8/getUpdates","r");
	fread(buffer, 2048, 1, fp);
	fclose(fp);

	parsed_json = json_tokener_parse(buffer);
	json_object_object_get_ex(parsed_json, "result", &result);
	i=json_object_array_length(result);           //Num de indices do array result
	


	if(i>0)
	{
		result_n=json_object_array_get_idx(result,i-1); //pegamos o ultimo array

		json_object_object_get_ex(result_n, "update_id", &update_id);
		json_object_object_get_ex(result_n, "message", &message);	
		json_object_object_get_ex(message, "text", &text);
	    strcpy(js.msg,json_object_get_string(text));
		js.updat_id=json_object_get_int(update_id);
	}
	js.valid=i;
return js;
}
// Função que incrementa o Contador
void* bot_data_RT (void *arg)
{



	system("wget -r -P /home/bruno/codigos_exemplos/  https://api.telegram.org/bot961579878:AAG4cVhRDowO13ZJ1vRm-3DHSiukfzQN2U8/getUpdates");

	struct json_struct json_dados;
    char linha2[200],off_set[200],off_set_rm[200],temp[]="/temp",foto[]="/retrato",bomba[]="/agua",comandos[]="/comandos";
    int i=8000,updat_id1=0,updat_id2=1;

    json_dados=dados_json();
    updat_id2=json_dados.updat_id;
while(1)
	{	
	printf("Baixando Site\n");
	system("wget -r -P /home/bruno/codigos_exemplos/  https://api.telegram.org/bot961579878:AAG4cVhRDowO13ZJ1vRm-3DHSiukfzQN2U8/getUpdates");

	json_dados=dados_json();
	updat_id1=json_dados.updat_id;
	if((updat_id1!=updat_id2) && (json_dados.valid>0))
	{
	    	printf("Comando recebido do bot\n");
	 		if (strcmp(temp,json_dados.msg)==0)
	 		{
	 			
	 			printf("Mande a temperatura\n");
	 			sprintf (linha2,"curl -s -X POST https://api.telegram.org/bot961579878:AAG4cVhRDowO13ZJ1vRm-3DHSiukfzQN2U8/sendMessage -d chat_id=658446605 -d text='quem é  %d'", varCompartilhada );
	 			system(linha2);
	 		
	 		}
	
	 		if(strcmp(foto,json_dados.msg)==0)
	 		{
	 			system("fswebcam -d /dev/video2 foto.jpg");
	 			system("curl -X POST https://api.telegram.org/bot961579878:AAG4cVhRDowO13ZJ1vRm-3DHSiukfzQN2U8/sendPhoto? -F chat_id=658446605 -F photo=@/home/bruno/codigos_exemplos/foto.jpg");

	 		}

	  		if(strcmp(bomba,json_dados.msg)==0)
	 		{

	 			system("curl -s -X POST https://api.telegram.org/bot961579878:AAG4cVhRDowO13ZJ1vRm-3DHSiukfzQN2U8/sendMessage -d chat_id=658446605 -d text='Recipiente Cheio'");

	 		}
	 		if(strcmp(comandos,json_dados.msg)==0)
	 		{

	 			system("curl -s -X POST https://api.telegram.org/bot961579878:AAG4cVhRDowO13ZJ1vRm-3DHSiukfzQN2U8/sendMessage -d chat_id=658446605 -d text='Ola :) Os comandos da sua DOGhouse são \n /temp: Informa a temperatura da casinha \n /retrato: Tira uma foto do interior da casinha \n /agua: Enche o recipiente de agua do cachorro'");
	 		
	 		}
	 		if(json_dados.valid>10)
	 		{
	 			sprintf(off_set,"wget -r -P /home/bruno/codigos_exemplos/  https://api.telegram.org/bot961579878:AAG4cVhRDowO13ZJ1vRm-3DHSiukfzQN2U8/getUpdates?offset=%d",updat_id1+1);
	 			system(off_set);
	 			sprintf(off_set_rm,"rm /home/bruno/codigos_exemplos/api.telegram.org/bot961579878:AAG4cVhRDowO13ZJ1vRm-3DHSiukfzQN2U8/'getUpdates?offset=%d'",updat_id1+1);
	 			system(off_set_rm);

	 		}

	}

	updat_id2=updat_id1;	  
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

	pthread_mutex_init(&mutexLock, NULL);
	pthread_create(&t0, NULL, bot_data_RT, NULL);
	pthread_create(&t1, NULL, DATA_GET, NULL);
	pthread_join(t0, NULL);
	pthread_join(t1, NULL);

	pthread_mutex_destroy(&mutexLock);

	printf("Valor final: %d\n", varCompartilhada);
	return 0;
}
