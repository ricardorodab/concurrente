#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

typedef struct chino {
  bool izquierdo;
  bool derecho;
  int invitados;
  int id;
} CHINO;

CHINO* init_chino(int id,int invitados);
void destroy_chino(CHINO *chino);
void come(CHINO *chino, bool *ten);
void come_zurdo(CHINO *chino, bool *ten);
