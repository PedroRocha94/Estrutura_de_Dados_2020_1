#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

struct fila{
    int inicio, final, qtd;
    struct aluno dados[MAX];
};


Fila* cria_fila(){
    Fila *fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

void libera_fila(Fila* fi){
    free(fi);
}

int tamanho_fila(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    return fi->qtd;
}

int fila_cheia(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    if(fi->qtd == MAX){
        return 1;
    }else{
        return 0;
    }

}

int fila_vazia(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    if(fi->qtd == 0){
        return 1;
    }else{
        return 0;
    }
}

int insere_fila(Fila* fi, struct aluno alu){
    if(fi == NULL){
        return 0;
    }
    if(fila_cheia(fi)){
        return 0;
    }
    fi->dados[fi->final] = alu;
    fi->final = (fi->final+1) % MAX;
    fi->qtd++;
    return 1;
}

int remove_fila(Fila* fi){
    if(fi == NULL){
        return 0;
    }
    if(fila_vazia(fi)){
        return 0;
    }
    fi->inicio = (fi->inicio + 1) % MAX;
    fi->qtd--;
    return 1;
}

int consulta_fila(Fila* fi, struct aluno *alu){
    if(fi == NULL){
        return 0;
    }
    if(fila_vazia(fi)){
        return 0;
    }
    *alu = fi->dados[fi->inicio];
    return 1;
}


int main(){

    Fila *fi;
    fi = cria_fila();

    struct aluno aluno1, aluno2, aluno3, aluno4;
    aluno1.matricula = 54;
    aluno2.matricula = 57;
    aluno3.matricula = 73;
    aluno4.matricula = 82;


    //int tamFila = tamanho_fila(fi);
    //printf("%d", tamFila);
    
    //int filaChei = fila_cheia(fi);
    //printf("%d", filaChei);
    
    //int filaVaz = fila_vazia(fi);
    //printf("%d", filaVaz);
    
    int insFila = insere_fila(fi, aluno1);
    int insFila2 = insere_fila(fi, aluno2);
    int insFila3 = insere_fila(fi, aluno3);
    int insFila4 = insere_fila(fi, aluno4);
    
    struct aluno test;
    //int consFila = consulta_fila(fi, &test);
    //printf("%d\n", test.matricula);

    int remFila = remove_fila(fi);

    int consFila2 = consulta_fila(fi, &test);
    printf("%d", test.matricula);
    
    libera_fila(fi);
    printf("\nFim do programa");
    return 0;
}