#include "lamport.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUMTHRDS 5

typedef struct Params {
  LAMPORT *l;
  int i;
} PARAM;

unsigned long var_global = 0;

void *haz_algo(void *thread_param)
{
  PARAM *param = (PARAM*)thread_param;
  int id = ((param->i));
  LAMPORT *l = param->l;
  while(1){
    lock(l,id);
    printf("Entra el thread %d \n",id);
    if(var_global >= 1000)
      break;
    var_global++;
    //sleep(0);
    printf("Sale el thread %d \n",id);
    unlock(l,id);
  }
  pthread_exit(NULL);
}

int main(int argc, char *argv[]){
  pthread_t threads[NUMTHRDS];
  LAMPORT l;
  PARAM *param;
  init(&l,NUMTHRDS);
  int i;
  for(i = 0; i < NUMTHRDS; i++){
    param = (PARAM*)malloc(sizeof(PARAM));
    param->l = &l;
    param->i = i;
    pthread_create(&threads[i],NULL,haz_algo,(void*)param);
  }
  while(var_global < 1000){ }
  printf("El valor final es de %lu \n",var_global);
  exit(0);
  pthread_exit(NULL);
  return 0;
}
