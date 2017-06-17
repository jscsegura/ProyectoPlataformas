/** @file lista.h
 *  @brief ...
 *
 *  @details ....
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

uint64_t memoryToBinary(char memory[]);
void casoCincoDoce(char* filename, char* tipo);
// void casoDiezVeinte(char* filename, char* tipo);
