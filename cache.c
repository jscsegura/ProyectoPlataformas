#include"cache.h"
#include"512.h"

uint64_t memoryToBinary(char memory[])
/* For each line, memoryToBits converts the value to "binary" (a uint64 that can have bitwise operations done on it) */
{
	uint64_t binary = 0;
	int i = 0;
	while(memory[i]!= '\n'){
   		if (memory[i]<= '9' && memory[i]>='0'){
   			binary = (binary*16) + (memory[i] - '0');
   		}else{
   			if(memory[i] == 'a'){
   		 		binary = (binary*16) + 10;
   		 	}
   		 	if(memory[i] == 'b'){
   		 		binary = (binary*16) + 11;
   		 	}
   		 	if(memory[i] == 'c'){
   		 		binary = (binary*16) + 12;
   		 	}
   		 	if(memory[i] == 'd'){
   		 		binary = (binary*16) + 13;
   		 	}
   		 	if(memory[i] == 'e'){
   		 		binary = (binary*16) + 14;
   		 	}
   		 	if(memory[i] == 'f'){
   		 		binary = (binary*16) + 15;
   		 	}
   		}
   	    i++;
   	}

    return binary;
}



void casoCincoDoce(char* filename, char* tipo){
  char fully[10];
  char eight[5];
  char direct[7];
  strcpy(fully, "asociativo");
  strcpy(eight, "8way");
  strcpy(direct, "directo");
  struct asociativo_512 cache_one;
  struct eightway_512 cache_two;
  struct directo_512 cache_three;
  cache_one.cache_hits = 0;
  cache_one.cache_misses = 0;
  cache_two.cache_hits = 0;
  cache_two.cache_misses = 0;
  cache_three.cache_hits = 0;
  cache_three.cache_misses = 0;

  for(int i =0; i<512; i++){
    cache_one.visits[i] = 0;
    cache_one.lines[i] = 0;
    cache_three.lines[i] = 0;
  }
  for(int x =0; x<64; x++){
    for(int y = 0; y<8; y++){
      cache_two.sets[x][y] = 0;
      cache_two.visits[x][y] = 0;
    }
   }




  char file[20];
    FILE *fp;

    /* opening file for reading */
    fp = fopen(filename , "r");

  while(fgets(file, 20, fp)!= NULL){
    uint64_t address = memoryToBinary(file);

    if(strncmp(tipo, fully, 17)==0){
      simulateAssoc512(&cache_one, address);
    }
    if(strncmp(tipo, eight, 24)==0){
      simulate8way512(&cache_two, address);
    }
    if(strncmp(tipo, direct, 19)==0){
      simulateDirect512(&cache_three, address);
    }
  }

  fclose(fp);


  if(strncmp(tipo, fully,17)==0){
    printf("Cache Hits: %d\n", cache_one.cache_hits);
    printf("Cache Misses: %d\n", cache_one.cache_misses);
    printf("Porcentaje de Hits: %.2f\n", (double)cache_one.cache_hits/(cache_one.cache_hits+cache_one.cache_misses));
    printf("Porcentaje de Misses: %.2f\n", (double)cache_one.cache_misses/(cache_one.cache_hits+cache_one.cache_misses));
  }
  if(strncmp(tipo, eight, 24)==0){
    printf("Cache Hits: %d\n", cache_two.cache_hits);
    printf("Cache Misses: %d\n", cache_two.cache_misses);
    printf("Porcentaje de Hits: %.2f\n", (double)cache_two.cache_hits/(cache_two.cache_hits+cache_two.cache_misses));
    printf("Porcentaje de Misses: %.2f\n", (double)cache_two.cache_misses/(cache_two.cache_hits+cache_two.cache_misses));
  }
  if(strncmp(tipo, direct, 19)==0){
    printf("Cache Hits: %d\n", cache_three.cache_hits);
    printf("Cache Misses: %d\n", cache_three.cache_misses);
    printf("Porcentaje de Hits: %.2f\n", (double)cache_three.cache_hits/(cache_three.cache_hits+cache_three.cache_misses));
    printf("Porcentaje de Misses: %.2f\n", (double)cache_three.cache_misses/(cache_three.cache_hits+cache_three.cache_misses));
  }
}

// void casoDiezVeinte(char* filename, char* tipo){
//   char fully[10];
//   char eight[5];
//   char direct[7];
//   strcpy(fully, "asociativo");
//   strcpy(eight, "8way");
//   strcpy(direct, "directo");
//   struct asociativo_1024 cache_one;
//   struct eightway_1024 cache_two;
//   struct directo_1024 cache_three;
//   cache_one.cache_hits = 0;
//   cache_one.cache_misses = 0;
//   cache_two.cache_hits = 0;
//   cache_two.cache_misses = 0;
//   cache_three.cache_hits = 0;
//   cache_three.cache_misses = 0;
//
//   for(int i =0; i<1024; i++){
//     cache_one.visits[i] = 0;
//     cache_one.lines[i] = 0;
//     cache_three.lines[i] = 0;
//   }
//   for(int x =0; x<128; x++){
//     for(int y = 0; y<8; y++){
//       cache_two.sets[x][y] = 0;
//       cache_two.visits[x][y] = 0;
//     }
//    }
//
//
//
//
//   char file[20];
//     FILE *fp;
//
//     /* opening file for reading */
//     fp = fopen(filename , "r");
//
//   while(fgets(file, 20, fp)!= NULL){
//     uint64_t address = memoryToBinary(file);
//
//     if(strncmp(tipo, fully, 17)==0){
//       simulateAssoc512(&cache_one, address);
//     }
//     if(strncmp(tipo, eight, 24)==0){
//       simulate8way512(&cache_two, address);
//     }
//     if(strncmp(tipo, direct, 19)==0){
//       simulateDirect512(&cache_three, address);
//     }
//   }
//
//   fclose(fp);
//
//
//   if(strncmp(tipo, fully,17)==0){
//     printf("Cache Hits: %d\n", cache_one.cache_hits);
//     printf("Cache Misses: %d\n", cache_one.cache_misses);
//     printf("Porcentaje de Hits: %.2f\n", (double)cache_one.cache_hits/(cache_one.cache_hits+cache_one.cache_misses));
//     printf("Porcentaje de Misses: %.2f\n", (double)cache_one.cache_misses/(cache_one.cache_hits+cache_one.cache_misses));
//   }
//   if(strncmp(tipo, eight, 24)==0){
//     printf("Cache Hits: %d\n", cache_two.cache_hits);
//     printf("Cache Misses: %d\n", cache_two.cache_misses);
//     printf("Porcentaje de Hits: %.2f\n", (double)cache_two.cache_hits/(cache_two.cache_hits+cache_two.cache_misses));
//     printf("Porcentaje de Misses: %.2f\n", (double)cache_two.cache_misses/(cache_two.cache_hits+cache_two.cache_misses));
//   }
//   if(strncmp(tipo, direct, 19)==0){
//     printf("Cache Hits: %d\n", cache_three.cache_hits);
//     printf("Cache Misses: %d\n", cache_three.cache_misses);
//     printf("Porcentaje de Hits: %.2f\n", (double)cache_three.cache_hits/(cache_three.cache_hits+cache_three.cache_misses));
//     printf("Porcentaje de Misses: %.2f\n", (double)cache_three.cache_misses/(cache_three.cache_hits+cache_three.cache_misses));
//   }
// }
