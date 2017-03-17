#include <stdlib.h>

typedef struct Lock {
  int *level;  
  int *victim;
  int numthr;
} FILTER;

FILTER* init(FILTER *f,int num_threads);
void destroy(FILTER *f);
void lock(FILTER *f, int id);
void unlock(FILTER *f, int id);
