#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int matricula;
    //char nome[30];
    //float n1, n2, n3;
};

typedef struct elemento* Lista;

Lista* cria_lista();

void libera_lista(Lista* li);

int tamanho_lista(Lista* li);

int lista_cheia(Lista* li);

int lista_vazia(Lista* li);

int insere_lista_inicio(Lista* li, struct aluno alu);

int insere_lista_final(Lista* li, struct aluno alu);

int insere_lista_ordenada(Lista* li, struct aluno alu);

int remove_lista_inicio(Lista* li);

int remove_lista_final(Lista* li);

int remove_eleme_qlq(Lista* li, struct aluno alu);

int consulta_lista_pos(Lista* li, int posicao, struct aluno *alu);

int consulta_lista_valor(Lista* li, int matricula, struct aluno *alu);