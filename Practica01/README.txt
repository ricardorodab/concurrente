DATOS:

Nombre: José Ricardo Rodríguez Abreu
Práctica: Práctica número 1.
Materia: Programación concurrente.
Fecha: Martes 7 de Febrero del 2017.
Compilador de documentación: doxygen

Punto 3:

- ¿Cuál es error?
	El error es que puede ocurrir un problema de sincronización al querer acceder
	al mismo tiempo a una variable en memoria global. Por lo que podría tener un
	problema al incrementar o al imprimir una variable ya que no es “thread safe”.

- ¿Qué mecanismos ofrece la biblioteca para solucionar este problema?
	La biblioteca ofrece un tipo de dato llamado “Mutex” que viene de “Mutual 
	exclusion”. Lo que ofrece es un tipo de variables seguras que involucran un tipo 
	de semáforo para el acceso a ellas.

Notas adicionales:
