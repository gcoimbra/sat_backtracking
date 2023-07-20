//
// Created by green on 18/10/18.
//

#include "Testes.h"

void testesImpossivel(SAT *impossivel)
{

	impossivel->clausulas = 7;
	impossivel->variaveis = 3;

	impossivel->formula = (char *) malloc(sizeof(char) * 3 * impossivel->clausulas);
	impossivel->atribuicoes = (unsigned char *) malloc(sizeof(unsigned char) * impossivel->variaveis);

	impossivel->atribuicoes[0] = 2;
	impossivel->atribuicoes[1] = 2;
	impossivel->atribuicoes[2] = 2;

	impossivel->formula[0] = 1;
	impossivel->formula[1] = 2;
	impossivel->formula[2] = 3;
	impossivel->formula[3] = -1;
	impossivel->formula[4] = 2;
	impossivel->formula[5] = 3;
	impossivel->formula[6] = 1;
	impossivel->formula[7] = -2;
	impossivel->formula[8] = 3;
	impossivel->formula[9] = 1;
	impossivel->formula[10] = 2;
	impossivel->formula[11] = -3;
	impossivel->formula[12] = -1;
	impossivel->formula[13] = -2;
	impossivel->formula[14] = 3;
	impossivel->formula[15] = 1;
	impossivel->formula[16] = -2;
	impossivel->formula[17] = -3;
	impossivel->formula[18] = -1;
	impossivel->formula[19] = 2;
	impossivel->formula[20] = -3;
//	impossivel->formula[21] = -1; impossivel->formula[22] = -2; impossivel->formula[23] = -3;
}

void testesParse(SAT *sat, char *arquivo_nome)
{
	FILE *file = fopen(arquivo_nome, "r");
	if (file == NULL)
	{
		perror("ERRO FATAL");
		exit(EXIT_FAILURE);
	}

	while (true)
	{
		char c = (char) fgetc(file);
		if (c == 'c')
		{
			do
				c = (char) fgetc(file);
			while (c != '\n');
		}
		else if (c == 'p')
		{
			do
				c = (char) fgetc(file);
			while (c != 'f');
			fgetc(file);

			fscanf(file, "%u %u\n", &sat->variaveis, &sat->clausulas);
				break;
		}
	}

	sat->formula = (char *) malloc(sizeof(char) * 3 * sat->clausulas);
	sat->atribuicoes = (unsigned char *) malloc(sizeof(unsigned char) * sat->variaveis);

	for (uint i = 0; i < sat->variaveis; ++i)
		sat->atribuicoes[i] = 2;

	for (uint j = 0; j < sat->clausulas * 3; j += 3)
		fscanf(file,"%d %d %d 0\n", (int *)&sat->formula[j], (int *)&sat->formula[j+1], (int *)&sat->formula[j+2]);

	fclose(file);
}