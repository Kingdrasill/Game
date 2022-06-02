#include "lista.h"

int main()
{
    srand(1);
	Lista l1, l2;
    int size=0;

	FLVazia(&l1);
	FLVazia(&l2);

    printf("\nTamanho das listas: ");
    scanf("%d", &size);

    Initialize(&l1, size);
    Initialize(&l2, size);
    
    Game(&l1, &l2);

	return 0;
}