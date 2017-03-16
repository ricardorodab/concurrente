#include "petersen.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUMTHRDS 2

typedef struct Params {
  PETERSEN *p;
  int *i;
} PARAM;

unsigned long var_global = 0;

void *haz_algo(void *thread_param)
{
  PARAM *param = (PARAM*)thread_param;
  int id = (*(param->i))-1;
  PETERSEN *p = param->p;
  while(1){
    lock(p,id);
    printf("<- Entra Thread %d \n",id);
    if(var_global >= 100000)
      break;
    var_global++;
    sleep(0);
    printf("-> Sale  Thread %d \n",id);
    unlock(p,id);
  }
  pthread_exit(NULL);
}

int main(int argc, char *argv[]){
  pthread_t threads[2];
  PETERSEN p;
  PARAM *param;
  init(&p);
  int i;
  for(i = 0; i < NUMTHRDS; i++){
    param = (PARAM*)malloc(sizeof(PARAM));
    param->p = &p;
    param->i = &i;
    pthread_create(&threads[i],NULL,haz_algo,(void*)param);
  }
  while(var_global < 100000){ sleep(1); }
  printf("El valor final es de %lu \n",var_global);
    
  pthread_exit(NULL);
  return 0;
}
