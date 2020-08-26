#include <stdio.h>
#include <stdlib.h>
#include "FilaDinamica.h"

struct fila{
    struct elemento *inicio;
    struct elemento *final;
};

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Fila* cria_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->final = NULL;
    }
    return fi;
}

void libera_fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int tamanho_fila(Fila* fi){
    if(fi == NULL){
        return 0;
    }
    int contador = 0;
    Elem* no = fi->inicio;
    while(no != NULL){
        contador++;
        no = no->prox;
    }
    return contador;
}

int fila_cheia(Fila* fi){
    return 0;
}

int fila_vazia(Fila* fi){
    if(fi == NULL){
        return 1;
    }
    if(fi->inicio == NULL){
        return 1;
    }
    return 0;
}

int insere_fila(Fila* fi, struct aluno alu){
    if(fi == NULL){
        return 0;
    }
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = alu;
    no->prox = NULL;
    if(fi->final == NULL){
        fi->inicio = no;
    }else{
        fi->final->prox = no;
    }
    fi->final = no;
    return 1;
}

int remove_fila(Fila* fi){
    if(fi == NULL){
        return 0;
    }
    if(fi->inicio == NULL){
        return 0;
    }
    Elem* no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL){
        fi->final == NULL;
    }
    free(no);
    return 1;
}

int consulta_fila(Fila* fi, struct aluno *alu){
    if(fi == NULL){
        return 0;
    }
    if(fi->inicio == NULL){
        return 0;
    }
    *alu = fi->inicio->dados;
    return 1;
}

int main(){

    Fila *fi;
    fi = cria_fila();

    struct aluno aluno1, aluno2, aluno3;
    aluno1.matricula = 48;
    aluno2.matricula = 87;
    aluno3.matricula = 97;

    int tamFila = tamanho_fila(fi);
    //printf("%d", tamFila);

    //int filaChe = fila_cheia(fi);
    //if(fila_cheia(fi))

    //int filaVaz = fila_vazia(fi);
    //if(fila_vazia(fi))

    int insFila = insere_fila(fi, aluno1);
    int insFila2 = insere_fila(fi, aluno2);
    int insFila3 = insere_fila(fi, aluno3);

    struct aluno test;
    int consFila = consulta_fila(fi, &test);
    printf("%d\n", test.matricula);

    int remFila = remove_fila(fi);   

    int consFila2 = consulta_fila(fi, &test);
    printf("%d", test.matricula);

    libera_fila(fi);
    return 0;
}