#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>


volatile int cnt=0,a=0;
static pthread_mutex_t mutexLock;


void* print_number(void *argumento)
{
	
	while(cnt<10)
	{
		if(a==0)
		{
			pthread_mutex_lock(&mutexLock);
				printf("%d\n", cnt);
				a=1;
			pthread_mutex_unlock(&mutexLock);
		}	
	}
	pthread_exit(0);
	
	
		
return NULL;
}

int main()
{
	int i=0;
	pthread_t thread_id1;
	pthread_mutex_init(&mutexLock, NULL); //inicia mutex
	pthread_create (&thread_id1, NULL, print_number, NULL);
 
   	for(i=0;i<10;i++)
    {	
    	sleep(1);
       	pthread_mutex_lock(&mutexLock);
    	cnt++;
    	a=0;
    	pthread_mutex_unlock(&mutexLock);

    }	
 	pthread_join(thread_id1, NULL);
	pthread_mutex_destroy(&mutexLock); //inicia mutex
	return -1;

return 0;
}