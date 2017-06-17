
#include <stdio.h>
#include <stdint.h>
#include <string.h>



struct directo_2048{
	uint64_t lines[2048];
	int cache_hits;
	int cache_misses;
};

struct asociativo_2048{
	uint64_t visits[2048];
	uint64_t lines[2048];
	int cache_hits;
	int cache_misses;
};

struct eightway_2048{
	uint64_t sets[256][8];
	uint64_t visits[256][8];
	int cache_hits;
	int cache_misses;
};

void simulateAssoc2048(struct asociativo_2048 *cache, uint64_t MemoryAddress);
void simulateDirect2048(struct directo_2048 *cache, uint64_t MemoryAddress);
void simulate8way2048(struct eightway_2048 *cache, uint64_t MemoryAddress);
void updateCache2048(struct asociativo_2048 *cache, uint64_t leading_bits);
void BringFromMemoryNWay2048(struct eightway_2048 *cache, uint64_t set, uint64_t tag);
