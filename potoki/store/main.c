#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>


#define MAX_CAPACITY 5000
#define NUM_CLIENTS 2
#define NUM_STORES 2


int stores[NUM_STORES];
pthread_t tid[NUM_CLIENTS+1];
int id[NUM_CLIENTS]= {1,2};
pthread_mutex_t ml[NUM_STORES]= PTHREAD_MUTEX_INITIALIZER;


void initStore(int *array, int n)
{
  for(int i=0;i<n;i++){
    array[i]= 900+rand()%200;
  }
}


void statStore(int *array,int n)
{
  printf("stores:\n");
  for(int i=0;i<n;i++){
    printf("[%d]=%4d",i+1,array[i]);
  }
  printf("\n");
}


void *client (void *id)
{
  int *client_id = (int *) id;
  int capacity =0;
  while (capacity<MAX_CAPACITY) 
  {
    int basket=0;
    int id;
    while(basket==0)
    {
      id=rand()% NUM_STORES;
      basket=stores[id];
    }
    pthread_mutex_lock(&ml[id]);
    if(stores[id]!=0)
    {
      capacity +=basket;
      stores[id]-=basket;
    }
    pthread_mutex_unlock(&ml[id]);
    printf("client %d: capcaity= %4d, pick up %4d int sotre %d\n", *client_id,capacity,basket, id+1);
    sleep(2);
  }
}


void *loader()
{
  int capacity = 500;
  while(1)
  {
    int id=rand()% NUM_STORES;
    pthread_mutex_lock(&ml[id]); //
    stores[id] += capacity;
    pthread_mutex_unlock(&ml[id]);
    printf("**loader: add %d in store %d\n", capacity,id+1);
    sleep(3);
  }
}


int main()
{

  srand(time(NULL));
  initStore(stores,NUM_STORES);
  statStore(stores,NUM_STORES);
  for(int i=0;i<NUM_CLIENTS;i++)
  {
    pthread_create(&tid[i],NULL, client,&id[i]);
  }
  pthread_create(&tid[NUM_CLIENTS], NULL,loader,NULL);


  for(int i=0;i<NUM_CLIENTS;i++)
  {
    pthread_join(tid[i],NULL);
  }
  pthread_cancel(tid[NUM_CLIENTS]);


  for(int i=0;i<NUM_CLIENTS;i++)
  {
    pthread_mutex_destroy(&ml[i]);
  }


  statStore(stores,NUM_STORES);


return 0;
}
