#include <pthread.h>
#include <stdio.h>

long a=0;
pthread_mutex_t m1 =  PTHREAD_MUTEX_INITIALIZER;

void *thread_calc(void *args)
{
  int i, tmp;
  for(i=0;i<180000;i++)
  {
    pthread_mutex_lock(&m1);
    a++;
    pthread_mutex_unlock(&m1);
  }

return NULL;
}



int main(void)
{
  int index[10];
  int i,i1;
  int *s;
  pthread_t thread[1000];
  for(i=0;i<1000;i++)
  {
    index[i]=i+1;
    pthread_create(&thread[i],NULL, thread_calc, NULL);
  }

  for(i1=0;i1<1000;i1++)
  {
    pthread_join(thread[i1], (void **)&s);
  }
  printf("a= %ld\n",a);

  return 0;
}


