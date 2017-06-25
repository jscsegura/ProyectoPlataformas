/** @file 512.c
 *  @brief Cache 512
 *  @details Contiene las funciones del caché de tamaño 512.
 */
#include"cache.h"
#include"512.h"

void simulateAssoc512(struct asociativo_512 *cache, uint64_t MemoryAddress)
{
	uint64_t leadingBits = MemoryAddress >> 6;

	for (int i = 0; i<512; i++){
		if (cache->lines[i] == leadingBits){
			cache->visits[i] += 1;
			cache->cache_hits += 1;
			return;
		}
	}
	cache->cache_misses +=1;
	updateCache(cache, leadingBits);
}

void simulateDirect512(struct directo_512 *cache, uint64_t MemoryAddress)
{
	uint64_t mask = 0xff;
	uint64_t cache_row = (MemoryAddress >> 6) & mask;
	uint64_t tag = MemoryAddress >> 15;

	if (cache->lines[cache_row] == tag){
		cache->cache_hits +=1;
	}else{
		cache->cache_misses += 1;
		cache->lines[cache_row] = tag;
	}
}

void simulate8way512(struct eightway_512 *cache, uint64_t MemoryAddress)
{
	uint64_t mask = 0x3f;
	uint64_t cache_set = (MemoryAddress >> 6) & mask;
	uint64_t tag = MemoryAddress >> 15;

	for(int i = 0; i <8; i++){
		if(cache->sets[cache_set][i] == tag){
			cache->cache_hits += 1;
			cache->visits[cache_set][i] += 1;
			return;
		}
	}

	cache->cache_misses += 1;
	BringFromMemoryNWay(cache, cache_set, tag);

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

void BringFromMemoryNWay(struct eightway_512 *cache, uint64_t set, uint64_t tag)
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
