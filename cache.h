/** @file cache.h
 *  @brief Este es el header del cache
 *  @details Este es el header del cache, en donde se redirigen los parámetros a las funciones según el tamaño del caché.
 *
 */


#include <stdio.h>
#include <stdint.h>
#include <string.h>



uint64_t memoryToBinary(char memory[]);
void casoCincoDoce(char* filename, char* tipo);
void casoDiezVeinte(char* filename, char* tipo);
void casoVeinteCuarenta(char* filename, char* tipo);
void casoCuarentaNoventa(char* filename, char* tipo);
