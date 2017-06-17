
#include <stdio.h>
#include <stdint.h>
#include <string.h>



struct directo_4096{
	uint64_t lines[4096];
	int cache_hits;
	int cache_misses;
};

struct asociativo_4096{
	uint64_t visits[4096];
	uint64_t lines[4096];
	int cache_hits;
	int cache_misses;
};

struct eightway_4096{
	uint64_t sets[512][8];
	uint64_t visits[512][8];
	int cache_hits;
	int cache_misses;
};

void simulateAssoc4096(struct asociativo_4096 *cache, uint64_t MemoryAddress);
void simulateDirect4096(struct directo_4096 *cache, uint64_t MemoryAddress);
void simulate8way4096(struct eightway_4096 *cache, uint64_t MemoryAddress);
void updateCache4096(struct asociativo_4096 *cache, uint64_t leading_bits);
void BringFromMemoryNWay4096(struct eightway_4096 *cache, uint64_t set, uint64_t tag);
