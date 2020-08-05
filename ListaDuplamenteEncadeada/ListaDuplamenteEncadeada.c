#include <stdio.h>
#include <stdlib.h>
#include "ListaDuplamenteEncadeada.h"

//20:33

struct elemento{
    struct elemento *anterior;
    struct aluno dados;
    struct elemento *proximo;
};

typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->proximo;
            free(no);
        }
        free(li);
    }

}

int tamanho_lista(Lista* li){
    if(li == NULL){
        return 0;
    }
    int contador = 0;
    Elem* no = *li;
    while(no != NULL){
        contador++;
        no = no->proximo;
    }
    printf("Contador deu: ");
    return contador;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL){
        return 1;
    }
    if(*li == NULL){
        return 1;
    }
    return 0;

}

int insere_lista_inicio(Lista* li, struct aluno alu){

    if(li == NULL){
        return 0;
    }
    Elem* no = (Elem*) malloc(sizeof(Elem)); 
    if(no == NULL){
        return 0;
    }
    no->dados = alu;
    no->anterior = NULL;
    no->proximo = (*li);
    if(*li != NULL){
        (*li)->anterior = no;
    }
    *li = no;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno alu){

    if(li == NULL){
        return 0;
    }
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = alu;
    if(lista_vazia(li)){
        no->proximo = NULL;
        no->anterior = NULL;
        *li = no;
        return 1;
    }else{
        Elem *ante, *atual = *li;
        while(atual != NULL && atual->dados.matricula < alu.matricula){
            ante = atual;
            atual = atual->proximo;
        }
        if(atual == *li){
            no->anterior = NULL;
            (*li)->anterior = no;
            no->proximo = (*li);
            *li = no;
        }else{
            no->proximo = ante->proximo;
            no->anterior = ante;
            ante->proximo = no;
            if(atual != NULL){
                atual->anterior = no;
            }
        }

        return 1;
    }
}

//int insere_lista_final(Lista* li, struct aluno alu);

int remove_lista_inicio(Lista* li){
    if(li == NULL){
        return 0;
    }
    if(*li == NULL){
        return 0;
    }

    Elem* no = *li;
    *li = no->proximo;
    if(no->proximo != NULL){
        no->proximo->anterior = NULL;
    }
    free(no);
    return 1;
}

//remover elemento qualquer


int remove_lista_final(Lista* li){
    if(li == NULL){
        return 0;
    }
    if(*li == NULL){
        return 0;
    }
    Elem* no = *li;
    while(no->proximo != NULL){
        no = no->proximo;
    }
    if(no->anterior == NULL){
        *li = no->proximo;
    }else{
        no->anterior->proximo = NULL;
    }
    free(no);
    return 1;

}

int consulta_lista_pos(Lista* li, int matricula, struct aluno alu){


    
}

int main(){

    struct aluno aluno, aluno2;
    aluno.matricula = 65;
    aluno.matricula = 68;

    Lista* li = cria_lista();

    //int tamanhoLista = tamanho_lista(li);
    //printf("%d", tamanhoLista);

    //int listaVazia = lista_vazia(li);
    //printf("%d", listaVazia);

    //int insAluIni = insere_lista_inicio(li, aluno);

    //int insAluOrd = insere_lista_ordenada(li, aluno2);

    //int remLisIni = remove_lista_inicio(li);

    //int remLisFim = remove_lista_final(li);

    libera_lista(li);
    return 0;
}