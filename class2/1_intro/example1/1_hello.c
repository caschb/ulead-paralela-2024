#include <stdio.h>
// ^ Esto es un include statement, sirve para traer código de otros archivos
//   bibliotecas para que pueda ser utilizado en el archivo
//   actual. Note que esta línea empieza con un #. Esto es lo que
//   llamamos un comando del pre-procesador. El pre-procesador tiene
//   algunas reglas distintas al resto del lenguaje de programación ya
//   que este se evalúa antes de la compilación del programa. Note
//   también que el nombre del archivo está rodeado de < >. Por lo general esto
//   indica que el archivo es parte de una biblioteca externa, a
//   diferencia de si hubiera estado rodeado de " " lo que indicaría
//   que es un archivo en la misma carpeta actual.


// En C todos los programas empiezan desde la función main. Esta
// función puede ser definida como:
// int main(void)  O  int main(int argc, char ** argv)
// En este caso como no recibimos argumentos se utiliza la primer
// forma.
int main(void) // Las funciones en C son un ejemplo de lo que se llama
               // compound statements. Los compound statements están
               // formados por simple statements, que son las líneas
               // que terminan con ;.
{
  printf("Hello, world!\n"); // Este programa simplemente imprime un
                             // saludo y termina.
  return 0;
}

// Para compilar el programa existen varias opciones. La más sencilla
// es utilizando el compilador directamente. Para hacer esto, desde la
// terminal se corre:
// gcc 1_hello.c -o hello
// Esto va a crear un archivo llamado hello. Para ejecutar el programa
// entonces se corre:
// ./hello
