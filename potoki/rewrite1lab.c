#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


#define NTHREADS 4
#define MAX 1000000


int A=0;
pthread_mutex_t MUTEX=PTHREAD_MUTEX_INITIALIZER;
typedef struct
{
int thread_num;
}PthreadData;


void *increment(void *inputData)
{
PthreadData *data=(PthreadData *)inputData;
int i,tmp;
for(i=0;i<MAX/NTHREADS;i++)
  {
  pthread_mutex_lock(&MUTEX);
  tmp=A;
  tmp++;
  A=tmp;
  pthread_mutex_unlock(&MUTEX);
  }
printf("THreadn num %d sum data= %d\n",data->thread_num,A);
return 0;
}


int main()
{
pthread_t *thread;
PthreadData *data;
int status;
int i;


thread=malloc(sizeof(*thread)* NTHREADS);
data=malloc(sizeof(*data)*NTHREADS);


for(i=0;i<NTHREADS;i++)
{
data[i].thread_num=i+1;
status=pthread_create(&thread[i],NULL,increment,&data[i]);
}
for(i=0;i<NTHREADS;i++)
{
status=pthread_join(thread[i],NULL);
}


printf("Results= %d\n",A);
return 0;
}










