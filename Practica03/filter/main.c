#include "filter.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUMTHRDS 10

typedef struct Params {
  FILTER *f;
  int *i;
  int *num_thr;
} PARAM;

unsigned long var_global = 0;

void *haz_algo(void *thread_param)
{
  PARAM *param = (PARAM*)thread_param;
  int id = (*(param->i))-1;
  int num_thr = (*(param->i));
  FILTER *f = param->f;
  while(1){
    lock(f,id);
    if(var_global >= 100000)
      break;
    var_global++;
    sleep(0);
    unlock(f,id);
  }
  pthread_exit(NULL);
}

int main(int argc, char *argv[]){
  pthread_t threads[2];
  FILTER f;
  PARAM *param;
  init(&f,NUMTHRDS);
  int i;
  for(i = 0; i < NUMTHRDS; i++){
    param = (PARAM*)malloc(sizeof(PARAM));
    param->num_thr = malloc(sizeof(int));
    param->f = &f;
    param->i = &i;
    *(param->num_thr) = NUMTHRDS; 
    pthread_create(&threads[i],NULL,haz_algo,(void*)param);
  }
  while(var_global < 100000){ }
  printf("El valor final es de %lu \n",var_global);
  exit(0);
  pthread_exit(NULL);
  return 0;
}
