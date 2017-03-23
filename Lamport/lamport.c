#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "lamport.h"

LAMPORT* init(LAMPORT *l, int num_thread)
{
  l->flag = malloc(sizeof(int)*num_thread);
  l->label = malloc(sizeof(int)*num_thread);
  l->numthr = num_thread;
  int i;
  for(i = 0; i < num_thread; i++){
    (l->flag)[i] = 0;
    (l->label)[i] = 0;
  }
  l = malloc(sizeof(LAMPORT));
  return l;
}

void destroy(LAMPORT *l)
{
  free(l->flag);
  free(l->label);
  free(l);
}

int max(LAMPORT *l)
{
  int i;
  int max = 0;
  for(i = 0; i < l->numthr; i++){
    if((l->label)[i] > max){
      max = l->label[i];
    }
  }
  return max;
}

int hay_conflicto(LAMPORT *l, int i)
{
  int k;
  for(k = 0; k < l->numthr; k++){
    if(l->flag[k] &&
       ((l->label[k] < l->label[i]) || ((l->label[k] == l->label[i]) && k < i))){
      return 1;
    }
  }
  return 0;
}

void lock(LAMPORT *l, int id)
{
  int i = id;
  (l->flag)[i] = 1;
  (l->label)[i] = max(l)+1; 
  while(hay_conflicto(l,i)){}
}

void unlock(LAMPORT *l, int id)
{
  l->flag[id] = 0;
}
