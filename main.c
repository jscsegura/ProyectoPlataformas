#include"cache.h"

int main(int argc, char *argv[])
{

  char casouno[3];
	strcpy(casouno, "512");

  if(strncmp(argv[2], casouno, 5)==0){

  char* filename = argv[3];
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

		if(strncmp(argv[1], fully, 17)==0){
			simulateAssoc(&cache_one, address);
		}
		if(strncmp(argv[1], eight, 24)==0){
			simulate8way(&cache_two, address);
		}
		if(strncmp(argv[1], direct, 19)==0){
			simulateDirect(&cache_three, address);
		}
	}

	fclose(fp);


	if(strncmp(argv[1], fully,17)==0){
		printf("Cache Hits: %d\n", cache_one.cache_hits);
		printf("Cache Misses: %d\n", cache_one.cache_misses);
		printf("Porcentaje de Hits: %.2f\n", (double)cache_one.cache_hits/(cache_one.cache_hits+cache_one.cache_misses));
		printf("Porcentaje de Misses: %.2f\n", (double)cache_one.cache_misses/(cache_one.cache_hits+cache_one.cache_misses));
	}
	if(strncmp(argv[1], eight, 24)==0){
		printf("Cache Hits: %d\n", cache_two.cache_hits);
		printf("Cache Misses: %d\n", cache_two.cache_misses);
		printf("Porcentaje de Hits: %.2f\n", (double)cache_two.cache_hits/(cache_two.cache_hits+cache_two.cache_misses));
		printf("Porcentaje de Misses: %.2f\n", (double)cache_two.cache_misses/(cache_two.cache_hits+cache_two.cache_misses));
	}
	if(strncmp(argv[1], direct, 19)==0){
		printf("Cache Hits: %d\n", cache_three.cache_hits);
		printf("Cache Misses: %d\n", cache_three.cache_misses);
		printf("Porcentaje de Hits: %.2f\n", (double)cache_three.cache_hits/(cache_three.cache_hits+cache_three.cache_misses));
		printf("Porcentaje de Misses: %.2f\n", (double)cache_three.cache_misses/(cache_three.cache_hits+cache_three.cache_misses));
	}
}
}
