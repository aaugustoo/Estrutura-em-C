#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#define MAX 1000

struct lista {
    int elementos[MAX];
    int particao;
};

void inicializar(struct lista *l);
int inserirInicio(int valor, struct lista *l);
int inserirFim(int valor, struct lista *l);
int inserirPosicao(int valor,int posicao,struct lista *l);
int inserirOrdem(int valor, struct lista *l);
void exibir(struct lista *l);
void reverso(struct lista *l);
int removerInicio(struct lista *l);
int removerFim(struct lista *l);
int removerPosicao(int posicao,struct lista *l);
int removerValor(int valor,struct lista *l);
int procurar(int valor,struct lista *l);
int somatorio(struct lista *l);
int tamanho(struct lista *l);
int quadrado(struct lista *l);
int primo(int valor);
int qtdPrimos(struct lista *l);

#endif