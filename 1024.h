/** @file 1024.h
 *  @brief Cache 1024
 *  @details Contiene los structs y llamados a funciones del caché de tamaño 1024.
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>



struct directo_1024{
	uint64_t lines[1024];
	int cache_hits;
	int cache_misses;
};

struct asociativo_1024{
	uint64_t visits[1024];
	uint64_t lines[1024];
	int cache_hits;
	int cache_misses;
};

struct eightway_1024{
	uint64_t sets[128][8];
	uint64_t visits[128][8];
	int cache_hits;
	int cache_misses;
};

void simulateAssoc1024(struct asociativo_1024 *cache, uint64_t MemoryAddress);
void simulateDirect1024(struct directo_1024 *cache, uint64_t MemoryAddress);
void simulate8way1024(struct eightway_1024 *cache, uint64_t MemoryAddress);
void updateCache1024(struct asociativo_1024 *cache, uint64_t leading_bits);
void BringFromMemoryNWay1024(struct eightway_1024 *cache, uint64_t set, uint64_t tag);
