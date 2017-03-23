typedef struct Threads {
  int *flag;
  int *label;
  int numthr;
} LAMPORT;


LAMPORT* init(LAMPORT *l, int num_thread);
void destroy(LAMPORT *l);
void lock(LAMPORT *l, int id);
void unlock(LAMPORT *f, int id);
