#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "petersen.h"

PETERSEN* init(PETERSEN *p)
{
  p = malloc(sizeof(PETERSEN));
  p->victim = -1;
  p->flags[0] = 0;
  p->flags[1] = 0;
  return p;
}

void destroy(PETERSEN *p)
{
  free(p);
}

void lock(PETERSEN *p,int id)
{  
  int j = 1-id;
  p->flags[id] = 1;
  p->victim = id;
  while(p->flags[j] && p->victim == id){}
}

void unlock(PETERSEN *p,int id )
{
  p->flags[id] = 0;
}

