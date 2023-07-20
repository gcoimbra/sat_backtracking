#ifndef SOL3_SAT_H
#define SOL3_SAT_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#define OFFSET 2 << ((sizeof(char)) - 1)  /* Deslocamento para sabermos se é negativo */

typedef struct SAT
{
	uint clausulas, variaveis;
	char *formula;
	unsigned char *atribuicoes;
} SAT;

#endif //SOL3_SAT_H
