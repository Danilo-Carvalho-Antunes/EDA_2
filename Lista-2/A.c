#include <stdio.h>
#include <stdlib.h>

#define M 1009

typedef struct celula {
    int chave;
    int ocorr;
    struct celula *prox;
} celula;

int hash(int chave) { return chave % M; }

void inicializa_hash(celula *th) {
    for (int i = 0; i < M; i++) {
        th[i].prox = NULL;
        th[i].ocorr = 0;
    }
}

int insere_hash(celula *th, int chave) {
    celula *elem;
    int posicao = hash(chave);

    for (elem = th[posicao].prox; elem != NULL && elem->chave != chave;elem = elem->prox);

    if (elem != NULL)
        elem->ocorr++;
    else {
        celula *nova = malloc(sizeof(celula));
        if (nova == NULL) return 1;
        nova->chave = chave;
        nova->ocorr = 1;
        nova->prox = th[posicao].prox;
        th[posicao].prox = nova;
    }

    return 0;
}

int busca_ocorr(celula *th, int chave) {
    celula *elem;
    int posicao = hash(chave);

    for (elem = th[posicao].prox; elem != NULL && elem->chave != chave;elem = elem->prox);

    if (elem != NULL)
        return elem->ocorr;
    else
        return 0;
}


void imprime_celulas(celula *th,int chave){
    if(th[chave].ocorr == 0) return;
    else{
        celula *cel;
        cel = th[chave].prox; 
        printf("%d -> %d\n",cel->chave,cel->ocorr);
        printf("|\n");
        printf("v\n");
        return;
    }

}


int main() {
    int N;
    scanf("%d", &N);

    celula *tb = calloc(M, sizeof(celula));
    inicializa_hash(tb);

    int nota;
    int count = 0;
    int maior_numero = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &nota);
        insere_hash(tb, nota);
    }

    for (int j = 0; j < M; j++) {
        //imprime_celulas(tb,j);
        if (tb[j].ocorr > count) {
            count = tb[j].ocorr;
            maior_numero = j;
        }
        else if (tb[j].ocorr == count && j > maior_numero) {
                maior_numero = j;
        }
    }

    printf("%d\n", maior_numero);
}