#include <stdio.h>
#include <stdlib.h>
#include "PilhaEstatica.h"

struct pilha{
    int qtd;
    struct aluno dados[MAX];
};

Pilha* cria_pilha(){
    Pilha *pi;
    pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->qtd = 0;
    }
    return pi;
}

void libera_pilha(Pilha* pi){
    free(pi);
}

int tamanho_pilha(Pilha* pi){
    if(pi == NULL){
        return -1;
    }else{
        return pi->qtd;
    }
}

int pilha_cheia(Pilha* pi){
    if(pi == NULL){
        return -1;
    }
    return (pi->qtd == MAX);
}

int pilha_vazia(Pilha* pi){
    if(pi == NULL){
        return -1;
    }
    return (pi->qtd == 0);
}

int insere_pilha(Pilha* pi, struct aluno alu){
    if(pi == NULL){
        return 0;
    }
    if(pilha_cheia(pi)){
        return 0;
    }
    pi->dados[pi->qtd] = alu;
    pi->qtd++;
    return 1;
}

int remove_pilha(Pilha* pi){
    if(pi == NULL){
        return 0;
    }
    if(pi->qtd == 0){
        return 0;
    }
    pi->qtd--;
    return 1;
}

int consulta_pilha(Pilha* pi, struct aluno *alu){
    if(pi == NULL){
        return 0;
    }
    if(pi->qtd == 0){
        return 0;
    }
    *alu = pi->dados[pi->qtd-1];
    return 1;
}

int main(){

    Pilha *pi;
    pi = cria_pilha();

    struct aluno aluno1, aluno2, aluno3;
    aluno1.matricula = 32;
    aluno2.matricula = 24;
    aluno3.matricula = 45;

    int tamPilha = tamanho_pilha(pi);
    //printf("%d", tamPilha);

    int piCheia = pilha_cheia(pi);
    if(pilha_cheia(pi));

    int piVaz = pilha_vazia(pi);
    if(pilha_vazia(pi));

    int insPilha = insere_pilha(pi, aluno1);
    int insPilha1 = insere_pilha(pi, aluno2);
    int insPilha2 = insere_pilha(pi, aluno3);

    struct aluno test;
    int consPilha = consulta_pilha(pi, &test);
    printf("%d\n", test.matricula);

    int remPilha = remove_pilha(pi);

    int consPilha2 = consulta_pilha(pi, &test);
    printf("%d\n", test.matricula);

    libera_pilha(pi);
    return 0;
}