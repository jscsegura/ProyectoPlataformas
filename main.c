/** @file main.c
 *  @brief Es el main del programa. Identifica los argumentos de entrada y los pasa al respectivo archivo.
 *
 *  @details El archivo toma los argumentos de entrada e identifica si estos son 512, 1024, 2048 y 4096, para posteriormente
 pasarlos al archivo correspondiente.
 */

#include"cache.h"

int main(int argc, char *argv[])
{

  char caso512[4];
  char caso1024[4];
  char caso2048[4];
  char caso4096[4];

	strcpy(caso512, "512");
  strcpy(caso1024, "1024");
  strcpy(caso2048, "2048");
  strcpy(caso4096, "4096");

  if(strncmp(argv[2], caso512, 5)==0){

  char* filename = argv[3];
  char* tipo = argv[1];
  casoCincoDoce(filename, tipo);

  }

  if(strncmp(argv[2], caso1024, 5)==0){

  char* filename = argv[3];
  char* tipo = argv[1];
  casoDiezVeinte(filename, tipo);

  }

  if(strncmp(argv[2], caso2048, 5)==0){

  char* filename = argv[3];
  char* tipo = argv[1];
  casoVeinteCuarenta(filename, tipo);

  }

  if(strncmp(argv[2], caso4096, 5)==0){

  char* filename = argv[3];
  char* tipo = argv[1];
  casoCuarentaNoventa(filename, tipo);

  }


}
