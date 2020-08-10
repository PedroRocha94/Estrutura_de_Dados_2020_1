#include <stdio.h>
#include <stdlib.h>
#include "ListaDinamicaCircular.h"

struct elemento{
    struct aluno dados;
    struct elemento *proximo;
};
typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li == NULL;
    }
    return li;
}

void libera_lista(Lista* li){
    if(li == NULL && (*li) == NULL){
        Elem* aux, *no = *li;
        while((*li) != no->proximo){
            aux = no;
            no = no->proximo;
            free(aux);
        }
        free(no);
        free(li);
    }

}

int tamanho_lista(Lista* li){
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    Elem* no = *li;
    int contador = 0;
    while(no != (*li)){
        no = no->proximo;
        contador++;
    }
    return contador;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL && (*li) == NULL){
        return 1;
    }else{
        return 0;
    }
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
    if((*li) == NULL){
        *li = no;
        no->proximo = no;
    }else{
        Elem *aux = *li;
        while(aux->proximo != (*li)){
            aux = aux->proximo;
        }
        aux->proximo = no;
        no->proximo = *li;
        *li = no;
    }
    
}

int insere_lista_ordem(Lista* li, struct aluno alu){
    if(li == NULL){
        return 0;
    }
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = alu;
    if((*li == NULL)){
        *li = no;
        no->proximo = no;
    }else{
        Elem* aux = *li;
        while(aux->proximo != (*li) && aux->proximo->dados.matricula < no->dados.matricula){
            aux = aux->proximo;
        }
        no->proximo = aux->proximo;
        aux->proximo = no;
    }
    return 1;

}

int insere_lista_final(Lista* li, struct aluno alu){
    if(li == NULL){
        return 0;
    }
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = alu;
    if((*li) == NULL){
        *li = no;
        no->proximo = no;
    }else{
        Elem *aux = *li;
        while(aux->proximo != (*li)){
            aux = aux->proximo;
        }
        aux->proximo = no;
        no->proximo = *li;
    }
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL){
        return 0;
    }
    if((*li) == NULL){
        return 0;
    }
    if((*li) == (*li)->proximo){
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem* atual = *li;
    while(atual->proximo != (*li)){
        atual = atual->proximo;
    }
    Elem* no = *li;
    atual->proximo = no->proximo;
    *li = no->proximo;
    free(no);
    return 1;

}

int remove_lista_final(Lista* li){
    if(li == NULL){
        return 0;
    }
    if((*li) == NULL){
        return 0;
    }
    if((*li) == (*li)->proximo){
        free(li);
        *li = NULL;
        return 1;
    }
    Elem* ant, *no = *li;
    while(no->proximo != (*li)){
        ant = no;
        no = no->proximo;
    }
    ant->proximo = no->proximo;
    free(no);
    return 1;
}

int remove_elemento_qlq(Lista* li, struct aluno alu){
    if(li == NULL){
        return 0;
    }
    if((*li) == NULL){
        return 0;
    }
    if((*li) == (*li)->proximo){
        free(*li);
        *li = NULL;
        return 1;
    }else{
        Elem *aux, *no = *li;
        while(no->proximo != (*li) && no->dados.matricula != alu.matricula){
            aux = no;
            no = no->proximo;
        }
        if(no->dados.matricula == alu.matricula){
            aux->proximo = no->proximo;
            free(no);
            return 1;
        }else{
            return -1;
        }
        
    }

}

int consulta_lista_posicao(Lista* li, int posicao, struct aluno *alu){
    if(li == NULL || (*li) == NULL || posicao <= 0){
        return 0;
    }
    Elem *no = *li;
    int i = 1;
    while(no->proximo != (*li) && i < posicao){
        no = no->proximo;
    }
    if(i != posicao){
        return 0;
    }else{
        *alu = no->dados;
        return 1;
    }
}

int consulta_lista_valor(Lista* li, int matricula, struct aluno *alu){
    if(li == NULL){
        return 0;
    }
    if((*li) == NULL){
        return 0;
    }
    Elem* no = *li;
    while(no->proximo != (*li) && no->dados.matricula != matricula){
        no = no->proximo;
    }
    if(no->dados.matricula != matricula){
        return 0;
    }else{
        *alu = no->dados;
        return 1;
    }
}


int main(){

    Lista *li;
    li = cria_lista();

    //int tam = tamanho_lista(li);
    //printf("O tamanho eh de %d", tam);

    //int lisChe = lista_cheia(li);
    //if(lista_cheia(li));

    //int lisVaz = lista_vazia(li);
    //printf("%d", lisVaz);

    struct aluno aluno, aluno2, aluno3;
    aluno.matricula = 50;
    aluno2.matricula = 55;
    aluno3.matricula = 59;

    //int insListIni = insere_lista_inicio(li, aluno);
    //printf("%d", insListIni);

    //int insListFim = insere_lista_final(li, aluno2);
    //printf("%d", insListFim);

    //int insLisOrd = insere_lista_ordem(li, aluno3);
    //printf("%d", insLisOrd);

    //int remLisIni = remove_lista_inicio(li);
    //printf("%d", remLisIni);

    //int remLisIni = remove_lista_inicio(li);
    //printf("%d", remLisIni);

    //int remEleQlq = remove_elemento_qlq(li, aluno2);
    //printf("%d", remEleQlq);

    //int posicao = 2;
    //struct aluno test;
    //int consLisPos = consulta_lista_posicao(li, posicao, &test);
    //printf("%d", test.matricula);
    
    //int matricula = 3;
    //struct aluno test;
    //int consLisVal = consulta_lista_valor(li, matricula, &test);

    libera_lista(li);
    return 0;
}