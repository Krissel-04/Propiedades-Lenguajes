#include <stdio.h>

int existe(int elemento, int conjunto[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        if (conjunto[i] == elemento) {
            return 1;
        }
    }
    return 0;
}

void unionConjuntos(int conjuntoA[], int tamanioA, int conjuntoU[], int tamanioU) {
    printf("Union de A y U: {");
    for (int i = 0; i < tamanioA; i++) {
        printf("%d", conjuntoA[i]);
        if (i < tamanioA - 1) {
            printf(", ");
        }
    }
    for (int i = 0; i < tamanioU; i++) {
        if (!existe(conjuntoU[i], conjuntoA, tamanioA)) {
            printf(", %d", conjuntoU[i]);
        }
    }

    printf("}\n");
}

void complemento(int conjuntoA[], int tamanioA, int conjuntoU[], int tamanioU){
    printf("Complemento de A y U: {");
    int primero = 1;
    for (int i = 0; i < tamanioU; i++) {
        if (!existe(conjuntoU[i], conjuntoA, tamanioA)) {
            if (!primero) {
                printf(", ");
            }
            printf("%d", conjuntoU[i]);
            primero = 0;
        }
    }
    printf("}\n");
}
