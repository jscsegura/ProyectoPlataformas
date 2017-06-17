
#include <stdio.h>
#include <stdint.h>
#include <string.h>


struct directo_512{
	uint64_t lines[512];
	int cache_hits;
	int cache_misses;
};

struct asociativo_512{
	uint64_t visits[512];
	uint64_t lines[512];
	int cache_hits;
	int cache_misses;
};

struct eightway_512{
	uint64_t sets[64][8];
	uint64_t visits[64][8];
	int cache_hits;
	int cache_misses;
};

void simulateAssoc512(struct asociativo_512 *cache, uint64_t MemoryAddress);
void simulateDirect512(struct directo_512 *cache, uint64_t MemoryAddress);
void simulate8way512(struct eightway_512 *cache, uint64_t MemoryAddress);
void updateCache(struct asociativo_512 *cache, uint64_t leading_bits);
void BringFromMemoryNWay(struct eightway_512 *cache, uint64_t set, uint64_t tag);
