#include"cache.h"

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

void simulateAssoc(struct asociativo_512 *cache, uint64_t memoryAccessed)
{
	uint64_t leading_twenty_six_bits = memoryAccessed >> 6;

	for (int i = 0; i<512; i++){
		if (cache->lines[i] == leading_twenty_six_bits){
			cache->visits[i] += 1;
			cache->cache_hits += 1;
			return;
		}
	}
	cache->cache_misses +=1;
	updateCache(cache, leading_twenty_six_bits);
}

void simulateDirect(struct directo_512 *cache, uint64_t memoryAccessed)
{
	uint64_t mask = 0xff;
	uint64_t cache_row = (memoryAccessed >> 6) & mask;
	uint64_t tag = memoryAccessed >> 15;

	if (cache->lines[cache_row] == tag){
		cache->cache_hits +=1;
	}else{
		cache->cache_misses += 1;
		cache->lines[cache_row] = tag;
	}
}

void simulate8way(struct eightway_512 *cache, uint64_t memoryAccessed)
{
	uint64_t mask = 0x3f;
	uint64_t cache_set = (memoryAccessed >> 6) & mask;
	uint64_t tag = memoryAccessed >> 12;

	for(int i = 0; i <8; i++){
		if(cache->sets[cache_set][i] == tag){
			cache->cache_hits += 1;
			cache->visits[cache_set][i] += 1;
			return;
		}
	}

	cache->cache_misses += 1;
	updateCache2(cache, cache_set, tag);

}

void updateCache(struct asociativo_512 *cache, uint64_t leading_bits)
{
	int lrv = cache->visits[0]; //least recently visisited
	for(int x = 0; x<512; x++){
		if(cache->visits[x] < lrv){
			lrv = cache->visits[x];
		}
	}

	for(int i= 0; i < 512; i++){
		if(cache->visits[i] == lrv){
			cache->lines[i] = leading_bits;
			cache->visits[i] = 0;
			return;
		}
	}
}

void updateCache2(struct eightway_512 *cache, uint64_t set, uint64_t tag)
{
	int lrv = cache->visits[set][0]; //least recently visisited
	for(int x = 0; x<8; x++){
		if(cache->visits[set][x] < lrv){
			lrv = cache->visits[set][x];
		}
	}

	for(int x = 0; x<8; x++){
		if(cache->visits[set][x] == lrv){
			cache->sets[set][x] = tag;
			cache->visits[set][x] = 0;
			return;
		}
	}
}
