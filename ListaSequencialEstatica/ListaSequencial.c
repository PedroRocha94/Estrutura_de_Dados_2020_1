#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
//**********************************************STRUCT DA LISTA******************************************************
struct lista{
    int qtd;
    struct aluno dados [MAX];
};
//**********************************************FUNÇÃO PARA CRIAR LISTA******************************************************
Lista *cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}
//**********************************************FUNÇÃO PARA LIBERAR ESPAÇO******************************************************
void libera_lista(Lista* li){
    free(li);
}
//**********************************************FUNÇÃO PARA VER TAMANHO DA LISTA******************************************************
int tamanho_lista(Lista* li){
    if(li ==NULL){
        return -1;
    }else{
        return li->qtd;
    }
}
//**********************************************FUNÇÃO PARA VERIFICAR O STATUS DA LISTA******************************************************
int lista_cheia(Lista* li){
    if(li == NULL){
        return -1;
    }
    return (li->qtd == MAX);
}

int lista_vazia(Lista* li){
    if(li == NULL){
        return -1;
    }
    return (li->qtd == 0);
}
//**********************************************FUNÇÃO PARA INSERIR ELEMENTOS NA LISTA******************************************************
int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    if(lista_cheia(li)){
        return 0;
    }
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    if(lista_cheia(li)){
        return 0;
    }
    int i = 0;
    for(i = li->qtd-1; i>=0; i--){
        li->dados[i+1] = li->dados[i];
    }
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int insere_ordem(Lista* li,  int pos, struct aluno al){
    if(li == NULL){
        return 0;
    }
    if(lista_cheia(li)){
        return 0;
    }
    int i = 0;
    for(i = pos; i <= tamanho_lista(li); i++){
        li->dados[i+1] = li->dados[i];
    }
    li->dados[pos] = al;
    li->qtd++;
    return 1;  

}
//**********************************************FUNÇÃO PARA REMOVER ELEMENTOS DA LISTA******************************************************
int remove_lista_final(Lista* li){
    if(li == NULL){
        return 0;
    }
    if(li->qtd == 0){
        return 0;
    }
    li->qtd--;
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL){
        return 0;
    }
    if(li->qtd == 0){
        return 0;
    }
    int k = 0;
    for(k = 0; k < li->qtd-1; k++){
        li->dados[k] = li->dados[k+1];
    }
    li->qtd--;
    return 1;
}

int remove_elemento_escolhido(Lista* li, int pos){
    if(li == NULL){
        return 0;
    }
    if(li->qtd == 0){
        return 0;
    }
    int i = 0;
    for(i = pos; i <= tamanho_lista(li); i++){
        li->dados[i] = li->dados[i+1];
    }



}

//**********************************************FUNÇÃO PARA VER UM ELEMENTO DA LISTA******************************************************
int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0 || pos > li->qtd){
        return 0;
    }
    *al = li->dados[pos-1];
    return 1;
}

int consulta_lista_conte(Lista* li, int valor){
    if(li == NULL){
        return 0;
    }
    int i = 0;
    for(i = 0; i <= tamanho_lista(li); i++){
        if(li->dados[i].matricula == valor){
            return 1;
        }
    }
    return 0;
}

//**********************************************FUNÇÃO PARA VER A LISTA COMPLETA******************************************************
void show(Lista* li){
    for(int i = 0; i<=tamanho_lista(li); i++){
        printf("%d, ", li->dados[i]);
    }

}
//**********************************************PROGRAMA PRINCIPAL******************************************************
int main(){

//**********************************************CRIAÇÃO DAS VARIAVEIS******************************************************
    Lista *li;

    struct aluno A1, A2, A3;

    A1.matricula = 1;
    A2.matricula = 2;
    A3.matricula = 3;

    int posicao = 1;

    li = cria_lista();
    
//**********************************************UTILIZAÇÃO DE ALGUMAS FUNÇÕES SIMPLES******************************************************

    int x = tamanho_lista(li);
    if(x == -1){
        printf("Lista inexistente");
    }else{
        printf("%d", x);
    }
    
    
    int y = lista_cheia(li);
    if(lista_cheia(li)){
        printf("Cheia");
    }
    
    int z = lista_vazia(li);
    if(lista_vazia(li)){
        printf("Vazia");
    }
//**********************************************REALIZANDO INSERÇÕES******************************************************
    int inf = insere_lista_final(li, A1);
    if(inf == 1){
        //show(li);
    }else{
        printf("Nao foi possivel inserir");
    }

    int nf = insere_lista_final(li, A2);
    if(inf == 1){
        //show(li);
    }else{
        printf("Nao foi possivel inserir");
    }

    int nf3 = insere_lista_final(li, A3);
    if(inf == 1){
        //show(li);
    }else{
        printf("Nao foi possivel inserir");
    }

    int ini = insere_lista_inicio(li, A1);
    if(inf == 1){
        //show(li);
    }else{
        printf("Nao foi possivel inserir");
    }

    int io = insere_ordem(li, posicao, A3);
    if(inf == 1){
        //show(li);
    }else{
        printf("Nao foi possivel inserir");
    }

//**********************************************REALIZANDO REMOÇÕES******************************************************
    int rf = remove_lista_final(li);
    if(inf == 1){
        //show(li);
    }else{
        printf("Nao foi possivel remover");
    }

    int ri = remove_lista_inicio(li);
    if(inf == 1){
        //show(li);
    }else{
        printf("Nao foi possivel remover");
    }

    int ree = remove_elemento_escolhido(li, posicao);
    //printf("\n");
    //show(li);

//**********************************************REALIZANDO CONSULTAS A LISTA******************************************************
    int cp = consulta_lista_pos(li, posicao, &A1);
    if(cp == 1){
        //show(li);
    }else{
        printf("Nao foi possivel consultar a lista");
    }
    int value = 1;
    int clc = consulta_lista_conte(li, value);
    printf("\n");
    if(clc == 0){
        printf("Nao existe esse valor");
    }else if(clc == 1){
        printf("Existe esse valor: %d", value);
    }
    

    libera_lista(li); // LIBERA TODA A MEMORIA DA LISTA
    return 0;
}