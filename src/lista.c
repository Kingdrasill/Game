#include "lista.h"

void Swap(Block *a, Block *b){
	Item aux;
	aux = a->data;
	a->data = b->data;
	b->data = aux;
	
}

void FLVazia(Lista *l){
	l->first = (Block*) malloc (sizeof(Block));
	l->last  = l->first;
	l->first->prox = NULL;
}

void LInsert(Lista *l, Item d){
	l->last->prox = (Block*) malloc (sizeof(Block));
	l->last = l->last->prox;
	l->last->data = d;
	l->last->prox = NULL;
}

void LRemove(Lista *l, Item d){
	Block *aux, *tmp;

	if(l->first == l->last || l == NULL || l->first->prox == NULL){
		printf("LISTA VAZIA!\n");
		return;
	}
	
	aux = l->first;
	while(aux->prox != NULL){
		if (aux->prox->data.val == d.val){
			tmp = aux;
			aux = aux->prox;
			tmp->prox = aux->prox;
			if (aux == l->last) {
				l->last = tmp;
            }
			free(aux);
		}
		else
			aux = aux->prox;
	}
}


void LImprime(Lista *l){
	Block *aux;

	aux = l->first->prox;
	while(aux != NULL){
		printf("%d\n", aux->data.val);
		aux = aux->prox;
	}

}

void Initialize(Lista *l, int size) {
    Item aux;

    for(int i=0; i<size; i++) {
        aux.val = rand()%13+1;
        LInsert(l, aux);
    }
}

void Game(Lista *l1, Lista *l2) {
	Block *aux1, *aux2;
	int number=0, soma1=0, soma2=0, i=0;

	number = rand()%13+1;
	printf("\nNumero a ser subtraido: %d\n", number);

	aux1 = l1->first->prox;
	aux2 = l2->first->prox;

	while(aux1 != NULL && aux2 != NULL) {
		printf("\nL1[%d] = %d \t L2[%d] = %d", i, aux1->data.val, i, aux2->data.val);

		soma1 += (aux1->data.val - number);
		soma2 += (aux2->data.val - number);
		
		aux1 = aux1->prox;
		aux2 = aux2->prox;
		i++;
	}

	if(soma1 > soma2)
		printf("\n\nA lista 1 ganhou!\n\n");
	else if(soma2 > soma1)
		printf("\n\nA lista 2 ganhou!\n\n");
	else
		printf("\n\nAs listas empataram!\n\n");
}