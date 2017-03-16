
typedef struct Threads {
  int victim;
  int flags[2];
} PETERSEN;

PETERSEN* init(PETERSEN* p);
void destroy(PETERSEN* p);
void lock(PETERSEN *p,int id);
void unlock(PETERSEN *p,int id);
