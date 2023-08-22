#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le) {
    int dado;
    if (le->prox == NULL) {
        printf("NULL\n");
    } else {
        while (le->prox != NULL) {
            le = le->prox;
            dado = le->dado;
            printf("%d -> ", dado);
        }
        if (le->prox == NULL) {
            printf("NULL\n");
        }
    }
}

void imprime_rec(celula *le) {
    int dado;
    if (le->prox == NULL) {
        printf("NULL\n");
        return;
    } else {
        le = le->prox;
        dado = le->dado;
        printf("%d -> ", dado);
    }
    imprime_rec(le);
}
