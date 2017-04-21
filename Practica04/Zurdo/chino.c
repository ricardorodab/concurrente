#include "chino.h"


CHINO* init_chino(int id,int invitados)
{
  CHINO *chino = malloc(sizeof(CHINO));
  chino->izquierdo = false;
  chino->derecho = false;
  chino->id = id;
  chino->invitados = invitados;
  return chino;
}


void destroy_chino(CHINO *chino)
{
  free(chino);
}

void come(CHINO *chino, bool *ten)
{
  printf("Empieza a comer el chino %d!\n",chino->id);
  bool *tenedores = (ten);
  while(!tenedores[chino->id]){}
  tenedores[chino->id] = false;
  chino->izquierdo = true;
  while(!tenedores[(chino->id+1)%chino->invitados]){}
  tenedores[(chino->id+1)%chino->invitados] = false;
  chino->derecho = true;
  printf("El filosofo  %d esta comiendo.\n",chino->id);
  
  tenedores[chino->id] = true;
  chino->izquierdo = false;
  tenedores[(chino->id+1)%chino->invitados] = true;
  chino->derecho = false;
  printf("El filosofo %d termino de comer.\n",chino->id);
  sleep(2);
}

void come_zurdo(CHINO *chino, bool *ten)
{
  printf("Empieza a comer el chino zurdo %d!\n",chino->id);
  bool *tenedores = (ten);
  while(!tenedores[(chino->id+1)%chino->invitados]){}
  tenedores[(chino->id+1)%chino->invitados] = false;
  chino->derecho = true;
  while(!tenedores[chino->id]){}
  tenedores[chino->id] = false;
  chino->izquierdo = true;
  printf("El filosofo zurdo %d esta comiendo.\n",chino->id);  
  tenedores[chino->id] = true;
  chino->izquierdo = false;
  tenedores[(chino->id+1)%chino->invitados] = true;
  chino->derecho = false;
  printf("El filosofo zurdo %d termino de comer.\n",chino->id);
  sleep(2);
}
