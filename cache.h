/** @file lista.h
 *  @brief ...
 *
 *  @details ....
 */

#ifndef LISTA_HPP
#define LISTA_HPP

#include <stdio.h>
#include <stdlib.h>
struct direct_mapped_Cache{
	uint64_t lines[512];
	int cache_hits;
	int cache_misses;
};

struct fully_assoc_Cache{
	uint64_t visits[512];
	uint64_t lines[512];
	int cache_hits;
	int cache_misses;
};

struct eightway_set_assoc_Cache{
	uint64_t sets[64][8];
	uint64_t visits[64][8];
	int cache_hits;
	int cache_misses;
};
