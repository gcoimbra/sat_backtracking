// Trabalho Prático II
// Projeto e Análise de Algoritmos
// Prof. Dr. Daniel Barbosa
// Gabriel Coimbra - 3044
// Dalila Vieira - 3030
// Outubro - 2018

#include "SAT.h"
#include "Solve.h"
#include "Testes.h"

int main()
{
	SAT sat;

	testesParse(&sat, "../testes/problem.cnf");

	printf("SAT? %d\n", solveBt(&sat, 0));

	for (uint i = 0; i < sat.variaveis; ++i)
		printf("%d ", sat.atribuicoes[i]);
	printf("\n");
}