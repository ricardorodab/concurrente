#include <stdio.h>
#include <stdlib.h>
#include "filter.h"

FILTER* init(FILTER *f,int num_threads)
{
  f->level = malloc(sizeof(int)*num_threads);
  f->victim = malloc(sizeof(int*)*num_threads);
  f->numthr = num_threads;
  int i;
  for(i = 0; i < num_threads;i++){
    (f->level)[i] = 0;
    (f->victim)[i] = 0;
  }
  f = malloc(sizeof(FILTER)+num_threads*sizeof(*(f->level)));
  return f;
}

void destroy(FILTER *f)
{
  free(f);
}

int hay_conflicto(FILTER *f, int me, int i)
{
  int k;
  for(k = 0; k < f->numthr; k++){
    if(k != me &&
       f->level[k] >= i &&
       f->victim[i] == me){
      return 1;
    }
  }
  return 0;
}


void lock(FILTER *f, int me)
{
  int i;
  for(i = 1; i < f->numthr; i++){
    f->level[me] = i;
    f->victim[i] = me;
    while(hay_conflicto(f,me,i)){}
  }
}


void unlock(FILTER *f, int me)
{
 f->level[me] = 0;
}

