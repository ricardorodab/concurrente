#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include "chino.h"


typedef struct Params {
  CHINO *chino;
  bool *tenedores;
  int id;
  bool zurdo;
} PARAM;


void msg_error(char *msg)
{
  printf("%s%s",msg,"\n");
}


void* come_chino(void *thread_param)
{
  PARAM *param = (PARAM*)thread_param;
  int id = param->id;
  bool *tenedores = (param->tenedores);
  CHINO* chino = param->chino;
  bool zurdo = (param->zurdo);
  if(!zurdo){
    while(true)
      {
	come(chino,tenedores);
      }
  }else{
    while(true)
      {
	come_zurdo(chino,tenedores);
      }
  }
}


int main(int argc, char **argv)
{
  srand(time(NULL));;
  int i;
  if(argc < 2)
    {
      msg_error("El numero de parametros es incorrecto");
      exit(-1);
    }
  int num_threads = atoi(argv[1]);
  if(!num_threads || num_threads < 0)
    {
      msg_error("El numero que debe pasar debe ser > 0");
      exit(-1);
    }
  CHINO *c;
  PARAM *param;
  pthread_t threads[num_threads];
  bool tenedores[num_threads];
  int random = rand()%num_threads;
  //Colocamos todos los tenedores en disponibles:
  for(i = 0; i < num_threads; i++)
    {
      tenedores[i] = true;
    }
  //Iniciamos los chinos.
  for(i = 0; i < num_threads; i++)
    {
      //Iniciamos a nuestro chino:
      c = init_chino(i,num_threads);
      //Lo que recibira cada funcion:
      param = malloc(sizeof(PARAM));
      param->chino = c;
      param->tenedores = tenedores;
      param->id = i;
      param->zurdo = false;
      if(i == random)
	param->zurdo = true;
      pthread_create(&threads[i],NULL,come_chino,(void*)param);
    }
  pthread_exit(NULL);
  return 0;
}
