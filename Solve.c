//
// Created by green on 18/10/18.
//

#include "Solve.h"

bool checkFormula(SAT *sat)
{
	// Verifica a fórmula dada a atribuição atual
	for (unsigned int clausula = 0; clausula < sat->clausulas; ++clausula)
	{
		unsigned char clausula_verdadeira = false;
		// Verifica uma clausula
		for (int var = 0; var < 3; ++var)
		{
			char variavel_atual = sat->formula[3*clausula + var];
			unsigned char valor_atual = (unsigned char) sat->atribuicoes[abs(variavel_atual) - 1];
			bool negada = (variavel_atual < 0);

			if(valor_atual == 2)
			{
				clausula_verdadeira = 2;
				continue;
			}

//			printf("Variavel: %d\tClausula: %d\tPosição: %d\tValor: %d\tResolve? %d Negada? %d\n", variavel_atual, clausula, var, valor_atual, valor_atual ^ negada, negada);
			if(valor_atual ^ negada)
			{
				clausula_verdadeira = true;
				break;
			}
		}

		if(clausula_verdadeira == 2)
		{
			#ifdef VERBOSE
				printf("Clausula %d em DONT CARE\n", clausula);
			#endif
			continue;
		}

		if(!clausula_verdadeira)
		{
			#ifdef VERBOSE
				printf("Clausula %d falsa, problema falso\n", clausula);
			#endif
			return false;
		}
	}
	return true;
}

bool solveBt(SAT *sat, uint passo)
{
	#ifdef VERBOSE
		printf("\n\nDEPTH DEPTH DEPTH DEPTH DEPTH DEPTH DEPTH DEPTH: %d\n", passo);
	#endif

	if(passo == sat->variaveis)
		return true;

	sat->atribuicoes[passo] = 1;
	#ifdef VERBOSE
		printf("Tentando 1...\n");
	#endif
	if(checkFormula(sat))
	{
		if (solveBt(sat, passo + 1))
			return true;
		else
		{
			sat->atribuicoes[passo] = 0;
			#ifdef VERBOSE
				printf("\n\nDEPTH DEPTH DEPTH DEPTH DEPTH DEPTH DEPTH DEPTH: %d", passo);
				printf("\nTentando 0...\n");
			#endif

			// Reseta soluções
			for (uint i = passo+1; i < sat->variaveis; ++i)sat->atribuicoes[i] = 2;

			if(checkFormula(sat))
			{
				if(solveBt(sat, passo + 1))
					return true;
			}
			else
				return false;
		}
	}
	else
	{
		sat->atribuicoes[passo] = 0;
		#ifdef VERBOSE
			printf("\n\nDEPTH DEPTH DEPTH DEPTH DEPTH DEPTH DEPTH DEPTH: %d", passo);
			printf("\nTentando 0...\n");
		#endif
		// Reseta soluções
		for (uint i = passo+1; i < sat->variaveis; ++i)sat->atribuicoes[i] = 2;

		if(checkFormula(sat))
		{
			if(solveBt(sat, passo + 1))
				return true;
		}
		else
			return false;
	}

}