#include <stdio.h>
#include <stdlib.h>

#ifndef HEAP_H
#define HEAP_H

//Definicao do tipo de funcao a ser utilizado para comparacao


typedef int COMP(void* x, void* y);

//Os elementos do vetor estao colocadoo no vetor de acordo com a ordem
typedef struct heap{
	int N;
	int P;
	void** elems;
	COMP* comparador;
}HEAP;

//Cria um heap vazio de tamanho n e com funcao de comparacao compara

HEAP* HEAP_create(int n, COMP* compara);

// Adiciona o elemento newelem ao Heap

void HEAP_add(HEAP* heap, void* newelem);

//Remove o menor elemento do heap

void* HEAP_remove(HEAP* heap);


#endif