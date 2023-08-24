#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int insere_inicio(celula *le, int dado) {
    celula *no = (celula *)malloc(sizeof(celula));
    if (no == NULL) return -1;
    if (le->prox == NULL) {
        no->dado = dado;
        le->prox = no;
        no->prox = NULL;
        return 1;
    } else {
        no->dado = dado;
        no->prox = le->prox;
        le->prox = no;
        return 1;
    }
}

int insere_antes(celula *le, int dado_x, int dado_y) {
    celula *no = (celula *)malloc(sizeof(celula));
    celula *ponteiro = (celula *)malloc(sizeof(celula));
    if (no == NULL) return -1;
    if (ponteiro == NULL) return -1;
    if (le->prox == NULL) {
        no->dado = dado_x;
        le->prox = no;
        no->prox = NULL;
        return 1;
    } else {
        no->dado = dado_x;
        no->prox = le->prox;
        ponteiro->prox = le->prox;
        while (no->prox->prox != NULL) {
            if (no->prox->dado == dado_y) {
                ponteiro->prox->prox = no;
                break;
            }

            no->prox = no->prox->prox;

            if (no->prox->dado == dado_y) {
                ponteiro->prox->prox = no;
                break;
            }

            ponteiro->prox = ponteiro->prox->prox;
        }

        if (no->prox->prox == NULL) {
            ponteiro->prox->prox = no;
            no->prox = NULL;
        }

        return 1;
    }
}