#include"cache.h"

int main(int argc, char *argv[])
{

  char casouno[2];
	strcpy(casouno, "512");

  if(strncmp(argv[2], casouno, 5)==0){

  char* filename = argv[3];
  char* tipo = argv[1];
  casoCincoDoce(filename, tipo);

  }
}
