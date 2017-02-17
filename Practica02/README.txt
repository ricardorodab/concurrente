DATOS:

Nombre: Jose Ricardo Rodriguez Abreu
Práctica: Práctica numero 2.
Materia: Programación concurrente.
Fecha: Martes 7 de Febrero del 2017.
Compilador de documentación: doxygen

Punto 3:

Son variables que permiten a los threads sincronizarse basados en la informacion
de las variables. Sin esta variables los threads estarían siempre manejando la
sección crítica del código.

Las variables de control en pthread tienen que ser declaradas de la siguiente manera:

pthread_cond_t myconvar = PTHREAD_COND_INITIALIZER;

El uso de las variables son muy similares al concepto de semáforos que se usa en
el sistema operativo.

Notas adicionales:
