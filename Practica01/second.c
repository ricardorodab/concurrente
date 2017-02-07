/* -------------------------------------------------------------------
 * second.c
 * version 1.0
 * Copyright (C) 2017  Jose Ricardo Rodriguez Abreu.
 * Facultad de Ciencias,
 * Universidad Nacional Autonoma de Mexico, Mexico.
 *
 * Este programa es software libre; se puede redistribuir
 * y/o modificar en los terminos establecidos por la
 * Licencia Publica General de GNU tal como fue publicada
 * por la Free Software Foundation en la version 2 o
 * superior.
 *
 * Este programa es distribuido con la esperanza de que
 * resulte de utilidad, pero SIN GARANTIA ALGUNA; de hecho
 * sin la garantia implicita de COMERCIALIZACION o
 * ADECUACION PARA PROPOSITOS PARTICULARES. Vease la
 * Licencia Publica General de GNU para mayores detalles.
 *
 * Con este programa se debe haber recibido una copia de la
 * Licencia Publica General de GNU, de no ser asi, visite el
 * siguiente URL:
 * http://www.gnu.org/licenses/gpl.html
 * o escriba a la Free Software Foundation Inc.,
 * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * -------------------------------------------------------------------
 */

/**
 * @file second.c
 * @author Jose Ricardo Rodriguez Abreu
 * @date 6 Feb 2017
 * @brief File containing the second exercise from the first practice for the
 * "Concurrent computing" class.
 *
 * Este programa utiliza la biblioteca Pthread para crear 50 hilos y modificar
 * una variable que compartan todas en memoria. Tiene como objetivo primario
 * identificar los posibles riesgos de la programacion concurrente.
 *
 * El programa usa el estandar de documentacion que define el uso de 
 * doxygen.
 *
 * @see https://github.com/ricardorodab/concurrente
 */

#include <stdio.h>
#include <pthread.h>

/**
 * @brief Constante.
 *
 * Es la constante que nos da el numero de Threads en el programa.
 */
#define NUM_THREADS 50

/**
 * @brief Variable global.
 *
 * Utilizamos una variable global para iterar y revisar el valor en pantalla.
 */
unsigned long var_global = 0;

/**
 * @brief Accion de Threads.
 *
 * Es la accion que va a realizar cada uno de los threads de este programa.
 */
void *imprimeSuma()
{
  while(1){    
    printf("Valor de la variable global es %lu\n",var_global);
    var_global++;
  }
  pthread_exit(NULL);
}

/**
 * @brief Metodo principal del programa.
 *
 * Es el metodo que genera los 50 threads y los pone a correr imprimeSuma().
 */
int main(void)
{
  pthread_t threads[NUM_THREADS];
  int exito;
  int i;
  for(i = 0; i < NUM_THREADS; i++)
    {
      exito = pthread_create(&threads[i], NULL, imprimeSuma, NULL);
      if(exito)
	{
	  printf("ERROR al crear el thread %d. Linea: %d\n",i,__LINE__);
	}
    }
  
  pthread_exit(NULL);
  return 0;
}

