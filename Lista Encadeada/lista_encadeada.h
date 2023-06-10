#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct no{
        int elemento;
        struct no* proximo;
}no;

typedef no* lista;

lista inserir_inicio (lista l, int valor);
void exibir(lista l);
void exibir_reversa(lista l);
lista inserir_fim(lista l, int valor);
lista inserir_posicao(lista l, int posicao, int valor);
lista inserir_ordem(lista l, int valor);
lista remover_inicio(lista l);
lista remover_fim(lista l);
lista remover_posicao(lista l, int posicao);
lista remover_valor(lista l, int valor);
int procurar_posicao(lista l, int valor);
int somatorio(lista l);
int tamanho(lista l);
lista lista_quadrada(lista l);
int primo(int valor);
int quantidade_primos(lista l);

#endif