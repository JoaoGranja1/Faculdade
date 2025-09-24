#include <stdio.h>
#include <stdlib.h>

typedef struct noA {
    char info;
    struct noA *esq;
    struct noA *dir;
} TNoA;

TNoA *inicializa(void);
void imprime(TNoA *nodo, int tab);
TNoA *criaNo(char ch);


TNoA *inicializa(void) {
    return NULL;
}

void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%c\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

TNoA *criaNo(char ch) {
    TNoA *novo;
    novo = (TNoA *) malloc(sizeof(TNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}


int COntarNo(TNoA *v){
    if(v == NULL) return 0;
    return 1 + COntarNo(v->esq) + COntarNo(v->dir);
}

void CaminhoProfundidadeRecursivo(TNoA *v){
    if(v == NULL) return;
    printf("%c ", v->info);
    CaminhoProfundidadeRecursivo(v->esq);
    CaminhoProfundidadeRecursivo(v->dir);
}

void CaminhoSimetricoRecursivo(TNoA *v){
    if(v == NULL) return;
    CaminhoSimetricoRecursivo(v->esq);
    printf("%c ", v->info);
    CaminhoSimetricoRecursivo(v->dir);
}

void CaminhoPosOrdemRecursivo(TNoA *v){
    if(v == NULL) return;
    CaminhoPosOrdemRecursivo(v->esq);
    CaminhoPosOrdemRecursivo(v->dir);
    printf("%c ", v->info);
}





int main(void) {
    TNoA *raiz;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('D');
    raiz->dir->dir = criaNo('E');
    imprime(raiz, 0);
}
