#include<stdlib.h>
#include<stdio.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula* start_cel(){
    celula* le = (celula*)malloc(sizeof(celula));
    le->prox = NULL;
    return le;
}

int insere_inicio(celula *le,int dado){
    celula *no = (celula*)malloc(sizeof(celula));
    if (no == NULL) return -1;
    if(le ->prox == NULL){
        no->dado = dado;
        le->prox = no;
        no->prox = NULL;
        return 1;
    }
    else{
        no->dado = dado;
        no->prox = le->prox;
        le->prox = no;
        return 1;
    }
}

int insere_antes(celula *le,int dado_x,int dado_y){
    celula *no = (celula*)malloc(sizeof(celula));
    celula *ponteiro = (celula*)malloc(sizeof(celula));
    if (no == NULL) return -1;
    if (ponteiro == NULL) return -1;
    if(le->prox == NULL){
        no->dado = dado_x;
        le->prox = no;
        no->prox = NULL;
        return 1;
    }
    else{
        no->dado = dado_x;
        no->prox = le->prox;
        ponteiro->prox = le->prox;
        while(no->prox->prox != NULL){

            if(no->prox->dado == dado_y ){
                ponteiro->prox->prox = no;
                break;
            }

            no->prox = no->prox->prox;

            if(no->prox->dado == dado_y ){
                ponteiro->prox->prox = no;
                break;
            }

            ponteiro->prox = ponteiro->prox->prox;
    
        }

        if(no->prox->prox == NULL){
            ponteiro->prox->prox = no;
            no->prox = NULL;
        }

        return 1;
    }
}

void imprime_rec(celula *le){
    int dado;
    if(le->prox == NULL){
        printf("NULL\n");
        return;
    }
    else{
        le = le->prox;
        dado = le->dado;
        printf("%d -> ",dado);
    }
    imprime_rec(le);
}

void imprime_cel(celula *le){
    int dado;
    if(le->prox == NULL){
        printf("NULL\n");
    }
    else{
        while(le->prox != NULL){
            le = le->prox;
            dado = le->dado;
            printf("%d -> ",dado);
        }
        if(le->prox == NULL){
            printf("NULL\n");
        }
    }
}

int remove_depois(celula*p){
    if(p->prox == NULL){
        return -1;
    }
    
    else{
        
        p->prox = p->prox->prox;

        return 1;
    }
    
}

void remove_elemento(celula *le, int dado){
    celula *no = (celula *)malloc(sizeof(celula));
    celula *ponteiro = (celula *)malloc(sizeof(celula));
    if (no == NULL) return ;
    if (ponteiro == NULL) return ;

    if(le->prox == NULL){
        return ;
    }
    if(le->prox->prox == NULL){
        return ;
    }
    
        no->prox = le->prox;
        ponteiro->prox = le->prox;

        if(no->prox->dado == dado){
            le->prox = no->prox->prox;
            return;
        }

        no->prox = le->prox;
        ponteiro->prox = le->prox;

        while (no->prox->prox != NULL) {

            if (no->prox->prox->dado == dado) {
                no->prox = no->prox->prox;
                ponteiro->prox->prox = no->prox->prox;
                break;
            }
            no->prox = no->prox->prox;
            ponteiro->prox = ponteiro->prox->prox;
        }

    return ;

}

void remove_todos_elementos(celula *le, int dado){
    celula *no = (celula *)malloc(sizeof(celula));
    celula *ponteiro = (celula *)malloc(sizeof(celula));
    if (no == NULL) return ;
    if (ponteiro == NULL) return ;

    if(le->prox == NULL){
        return ;
    }
    if(le->prox->prox == NULL){
        return ;
    }
    
        no->prox = le->prox;
        ponteiro->prox = le->prox;

        if(no->prox->dado == dado){
            le->prox = no->prox->prox;
        }

        no->prox = le->prox;
        ponteiro->prox = le->prox;

        while (no->prox->prox != NULL) {

            if (no->prox->prox->dado == dado) {
                ponteiro->prox = ponteiro->prox->prox;
                no->prox->prox = ponteiro->prox->prox;
                //
                ponteiro->prox = no->prox;
                continue;
            }
                no->prox = ponteiro->prox->prox;
                ponteiro->prox = ponteiro->prox->prox;

        }

    return;
}

celula *busca(celula *le,int dado){
    celula *no = (celula *)malloc(sizeof(celula));
    celula *ponteiro = (celula *)malloc(sizeof(celula));
    if (no == NULL) return NULL;
    if (ponteiro == NULL) return NULL ;
    
    no->prox = le->prox;
    ponteiro->prox = le->prox;
    
    while(no->prox->prox != NULL){
        if(no->prox->dado == dado){
            ponteiro = no;
            return ponteiro;
        }
        no->prox = no->prox->prox;
    }
        
}

    

celula *busca_rec(celula *le,int dado){
    celula *no = (celula *)malloc(sizeof(celula));
    if (no == NULL) return NULL;

    no->prox = le->prox;

    if(no->prox == NULL){
        return NULL;
    }
    
    if(no->prox->dado == dado){
        return no;
    }

    no->prox = no->prox->prox;

    return busca_rec(no,dado);
        
}



int main(){
    celula *le = start_cel();
    celula *lo = start_cel();

    remove_depois(le);
    remove_elemento(le,18);
    remove_todos_elementos(le,8);
    
    insere_inicio(lo,1);
    insere_inicio(lo,3);
    insere_inicio(lo,1);
    insere_inicio(lo,6);
    insere_inicio(lo,1);
    insere_inicio(lo,9);
    insere_inicio(lo,1);
    insere_inicio(lo,12);
    insere_inicio(lo,1);

    imprime_rec(lo);

    celula *ponteiro0_teste;
    celula *ponteiro1_teste;
    celula *ponteiro2_teste;
    celula *ponteiro3_teste;

    ponteiro0_teste = busca_rec(lo,6);

    ponteiro1_teste = busca(lo,9);

    imprime_cel(ponteiro0_teste);

    imprime_cel(ponteiro1_teste);

}