#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

lista inserir_inicio (lista l, int valor){
       lista novo = (lista)malloc(sizeof(no));
       novo->elemento = valor;
       novo->proximo = l;
       return novo;
}

void exibir(lista l){
       if(l == NULL){
              printf("A lista esta vazia.\n");
              return;
       }
       lista auxiliar = l;
       while(auxiliar != NULL){
              printf("[%d]",auxiliar->elemento);
              auxiliar = auxiliar->proximo;
       }
       printf("\n");
}

void exibir_reversa(lista l){
       if(l == NULL){
              return;
       }
       exibir_reversa(l->proximo);
       printf("[%d]",l->elemento);
}

lista inserir_fim(lista l, int valor){
       lista auxiliar = l;
       if(auxiliar == NULL){
              return inserir_inicio(l,valor);
       }
       
       while(auxiliar->proximo != NULL){
              auxiliar = auxiliar->proximo; 
       }

       lista novo = (lista)malloc(sizeof(no));
       novo->elemento = valor;
       novo->proximo = NULL;

       auxiliar->proximo = novo;
       return l;
}

lista inserir_posicao(lista l, int posicao, int valor){
       int i = 0;
       lista temporaria = l;
       while(temporaria->proximo != NULL){
             temporaria = temporaria->proximo;
             i++; 
       }

       if(l == NULL){
              return NULL;
       }
       
       if(posicao == 0){
              return inserir_inicio(l, valor);
       }
       
       if(posicao == i+1){
              return inserir_fim(l, valor);
       }

       if(posicao > i){
              return l;
       }

       lista novo = (lista)malloc(sizeof(no));
       novo->elemento = valor;

       int contador = 0;
       lista auxiliar = l;
       while(contador < posicao-1){
              auxiliar = auxiliar->proximo;
              contador++;
       }
       novo->proximo = auxiliar->proximo;
       auxiliar->proximo = novo;
       return l;
}

lista inserir_ordem(lista l, int valor){
       if(l == NULL){
              return inserir_inicio(l, valor);
       }

       lista auxiliar = l;

       if(auxiliar->proximo == NULL){
              if(auxiliar->elemento < valor){
                     return inserir_fim(l, valor);
              }else if(auxiliar->elemento >= valor){
                     return inserir_inicio(l, valor);
              }
       }

       if(auxiliar->elemento >= valor){
              return inserir_inicio(l, valor);
       }

       while(auxiliar->elemento < valor && auxiliar->proximo != NULL && auxiliar->proximo->elemento < valor){
              auxiliar = auxiliar->proximo;
       }
       lista novo = (lista)malloc(sizeof(no));
       novo->elemento = valor;
       novo->proximo = auxiliar->proximo;
       auxiliar->proximo = novo;
       return l;
}

lista remover_inicio(lista l){
       if(l == NULL){
              printf("A lista esta vazia.\n");
              return NULL;
       }

       lista auxiliar = l->proximo;
       free(l);
       return auxiliar;
}

lista remover_fim(lista l){
       if(l == NULL){
              printf("A lista esta vazia.\n");
              return NULL;
       }
       if(l->proximo == NULL){
              return remover_inicio(l);
       }

       lista auxiliar = l;
       while(auxiliar->proximo->proximo != NULL){
              auxiliar = auxiliar->proximo;
       }

       free(auxiliar->proximo);
       auxiliar->proximo = NULL;
       return l;
}

lista remover_posicao(lista l, int posicao){
       int i = 0;
       lista temporaria = l;
       while(temporaria != NULL){
             i++;
             temporaria = temporaria->proximo; 
       }

       if(l == NULL){
              printf("A lista esta vazia.\n");
              return NULL;
       }
       
       if(posicao > i){
              printf("A lista nao possui a posicao informada.\n");
              return l;
       }

       if(posicao == 0){
              return remover_inicio(l);
       }

       if(posicao == i){
              return remover_fim(l);
       }

       int contador = 0;
       lista auxiliar = l;
       while(contador < posicao-1){
              auxiliar = auxiliar->proximo;
              contador++;
       }
       
       auxiliar->proximo = auxiliar->proximo->proximo;

       return l;
}

lista remover_valor(lista l, int valor){
       if(l == NULL){
              printf("A lista esta vazia.\n");
              return NULL;
       }
       
       int contador = 0;
       lista auxiliar = l;
       while(auxiliar != NULL){
              if(auxiliar->elemento == valor){
                     return remover_posicao(l, contador);
              }
              auxiliar = auxiliar->proximo;
              contador++;
       }

       if(auxiliar == NULL){
              printf("Esse elemento nao esta presente na lista.\n");
              return l;
       }
}

int procurar_posicao(lista l, int valor){
       if(l == NULL){
              printf("Lista vazia.\n");
              return 0;
       }
       
       int contador = 0;
       lista auxiliar = l;
       while(auxiliar != NULL){
              if(auxiliar->elemento == valor){
                     printf("A posicao do numero %d corresponde a %d.\n",valor,contador);
                     return contador;
              }
              auxiliar = auxiliar->proximo;
              contador++;
       }

       if(auxiliar == NULL){
              printf("Esse numero nao esta presente na lista.\n");
              return 0;
       }
}

int somatorio(lista l){
       int soma = 0;
       lista auxiliar = l;
       while(auxiliar != NULL){
              soma = soma + auxiliar->elemento;
              auxiliar = auxiliar->proximo;
       }
       printf("A soma do(s) elemento(s) da lista corresponde a %d.\n",soma);
       return soma;
}

int tamanho(lista l){
       if(l == NULL){
              printf("A lista esta vazia.\n");
              return 0;
       }
       int contador = 1;
       lista temporaria = l;
       while(temporaria->proximo != NULL){
             temporaria = temporaria->proximo;
             contador++; 
       }
       printf("A lista possui %d elemento(s).\n",contador);
       return contador;
}

lista lista_quadrada(lista l){
       if(l == NULL){
              printf("Lista vazia.\n");
              return NULL;
       }
       lista auxiliar = l;
       while(auxiliar != NULL){
              auxiliar->elemento = auxiliar->elemento * auxiliar->elemento;
              auxiliar = auxiliar->proximo;
       }
       return l;
}

int primo(int valor){
    int divisor;
    if(valor == 1){
       return 0;
    }

    for(divisor = 2; divisor <= (valor/2); divisor++){
       if(valor % divisor == 0){
            return 0;
       }
    }
    
    if(divisor >= (valor/2)){
       return 1;
    }
}

int quantidade_primos(lista l){
       if(l == NULL){
              printf("Lista vazia.\n");
              return 0;
       }
       int contador = 0;
       lista auxiliar = l;
       while(auxiliar != NULL){
             if(primo(auxiliar->elemento) == 1){
                contador ++;
             }  
             auxiliar = auxiliar->proximo;
       }
       printf("A quantidade de numeros primos da lista corresponde a %d.\n",contador);
       return contador;
}
