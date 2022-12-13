#include "heap.h"

//Aluno: alan victor soares vieira 
//matricula: 536784

HEAP* HEAP_create(int n, COMP* compara) {
	HEAP* heap = malloc(sizeof(HEAP));
	heap->elems = malloc(n * sizeof(void*));
	heap->N = n;
	heap->P = 0;
	heap->comparador = compara;

	return heap;
}

void HEAP_add(HEAP* heap, void* newelem) {
  if (heap->P < heap->N) {
    heap->elems[heap->P] = newelem;
	int pos = heap->P;

	while (heap->comparador(heap->elems[pos], heap->elems[(pos - 1) / 2]) > 0) {
		void* aux = heap->elems[pos];
		heap->elems[pos] = heap->elems[(pos - 1) / 2];
		heap->elems[(pos - 1) / 2] = aux;	
		pos = (pos - 1) / 2;
	}	

	heap->P++;
  }
}

void* HEAP_remove(HEAP* heap) {
	void* min = heap->elems[0];

	heap->elems[0] = heap->elems[heap->P - 1];
	heap->elems[heap->P - 1] = min;
	
	heap->P--;

	int a = 0;
	int b = a * 2 + 1;
	
	while (b < heap->P) {
		if (b + 1 < heap->P) {
			if (heap->comparador(heap->elems[b], heap->elems[b + 1]) < 0) {
				b += 1;
			}
		}

		if (heap->comparador(heap->elems[a], heap->elems[b]) < 0) {
			void* aux = heap->elems[a];
			heap->elems[a] = heap->elems[b];
			heap->elems[b] = aux;
			a = b;
			b = a * 2 + 1;
		} else {
			b = heap->P + 1;
		}
	}

	return min;
}

