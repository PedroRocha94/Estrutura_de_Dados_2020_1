#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ListaSimplesmenteEncadeada.h"
//*********************criando um nó que guardará o valor e um ponteiro para o próximo******************************
struct elemento{
    struct aluno dados;
    struct elemento *proximo;
};
typedef struct elemento Elem;

//*********************criando as funções que vão ser usadas******************************
//*********************função para ******************************

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
    int cont = 0;
    Elem *no = *li;
    while(no != NULL){
        cont++;
        no = no->proximo;
    }
    return cont;
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
    no->proximo = (*li);
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
        no->proximo = (*li);
        *li = no;
        return 1;
    }
    else{
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < alu.matricula){
            ant = atual;
            atual = atual->proximo;
        }
        if(atual == *li){
            no->proximo = (*li);
            *li = no;
        }else{
            no->proximo = ant->proximo;
            ant->proximo = no;
        }
        return 1;
    }


}

int insere_lista_final(Lista* li, struct aluno alu){
     if(li == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no->proximo == NULL){
        no->dados = alu;
        no->proximo = (*li);
        *li = no;
        return 1;
    }
}

int remove_lista_inicio(Lista* li){

    if(li = NULL){
        return 0;
    }
    if((*li) == NULL){
        return 0;
    }
    Elem *no = *li;
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
    Elem *ant, *no = *li;
    while(no->proximo != NULL){
        ant = no;
        no = no->proximo;
    }
    if(no == (*li)){
        *li = no->proximo;

    }else{
        ant->proximo = no->proximo;
    }
    free(no);
    return 1;
}

int remove_lista_meio(Lista* li, int matricula, struct aluno alu){
    if(lista_vazia(li)){
        return 0;
    }
    int tam = tamanho_lista(li);
    Elem  *ant, *no = *li;

    if(matricula == 1){
       remover_lista_inicio(li);
       return 1;
    }else if(matricula == tam){
       remover_lista_final(li);
       return 1;
    }else{
        while(no != NULL && no->dados.matricula != matricula){
            no= no->proximo;
        }
        if(no == NULL){
           return 0;
        }else{
           ant->proximo = no->proximo;
           free(no);
           return 1;
        }
    }
    return 0;
}

int consulta_lista_valor(Lista* li, int mat, struct aluno *alu){
    if(li == NULL){
        return 0;
    }
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->proximo;
    }

    if(no == NULL){
        return 0;
    }else{
        *alu = no->dados;
        return 1;
    }
    
}

int consulta_list_pos(Lista* li, int posicao, struct aluno *alu){
    int tamanho = tamanho_lista(li);
    if(lista_vazia(li)){
        return 0;
    }
    if(tamanho < posicao){
        return 0;
    }
    
    for(int i = 0; i <= tamanho; i++){
        if(i == posicao){
            return 1;
        }
    }
}





int main(){
    //criando a variavel tipo aluno

    //criando a lista
    Lista *li = (Lista*) malloc(sizeof(Lista));
    *li = NULL;

    struct aluno dados_aluno1, dados_aluno2, dados_aluno3;
    dados_aluno1.matricula = 1;   
    dados_aluno2.matricula = 2;
    dados_aluno3.matricula = 3;

    //int lisVaz = lista_vazia(li);

    //verificando o tamanho da lista
    //int tam = tamanho_lista(li);
    //printf("\n%d", tam);

    //para verificar se a lista está cheia mas não faz muito sentido em uma lista encadeada
    //int LisChe = lista_cheia(li);
    //printf("%d", LisChe);

    //verificar se a lista está vazia
    //
    //printf("%d", lisVaz);

    int iseAlu = insere_lista_inicio(li, dados_aluno1);
    show(li);
    
    int insAluOrd = insere_lista_ordenada(li, dados_aluno2);
    if(insAluOrd == 1){
        printf("\nInserido em ordem");
    }

    int iseFim= inserir_lista_final(li, dados_aluno3);
    if(iseFim == 1){
        printf("\nInserido no final");
    }

    int remIni = remove_lista_inicio(li);
    if(remIni == 1){
        printf("\nRemovido do inicio");
    }
    
    int remFim = remove_lista_final(li);
    if(remIni == 1){
        printf("\nRemovido do fim");
    }

    int remMei = remover_lista_meio(li, 3, dados_aluno3);
    if(remMei == 1){
        printf("\nRemovido o escolhido");
    }
    
    int mat = 2;
    int consVal = consulta_lista_valor(li, mat, &dados_aluno2);
    if(consVal == 1){
        printf("%d", dados_aluno2.matricula);
    }

    int conPos = consulta_lista_pos(li, 1, &dados_aluno1);
    if(conPos == 1){
        printf("%d", dados_aluno1.matricula);
    }
    
    
    //liberando a lista
    libera_lista(li);
    

    return 0;
}