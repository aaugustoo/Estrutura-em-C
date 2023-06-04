#include<stdio.h>
#include<stdlib.h>
#include"lista_sequencial.h"

#define MAX 1000

void inicializar(struct lista *l){
    l->particao = 0;
}

int inserirInicio (int valor, struct lista *l){
    if(l->particao < MAX){
    int i;
    for(i=l->particao; i>0; i--){
        l->elementos[i] = l->elementos[i-1];
    }
    l->elementos[0] = valor;
    l->particao ++;
    return 1;
}else{
    return 0;
}
}

int inserirFim(int valor, struct lista *l){
    if(l->particao < MAX){
    l->elementos[l->particao] = valor;
    l->particao ++;
    return 1;
}else{
    return 0;
}
}

int inserirPosicao(int valor,int posicao,struct lista *l){
    if(l->particao >= posicao && l->particao < MAX){
    int i;
    for(i=l->particao; i>posicao; i--){
        l->elementos[i] = l->elementos[i-1];
    }
    l->elementos[posicao] = valor;
    l->particao ++;
    return 1;
}else{
    return 0;
}
}

int inserirOrdem(int valor, struct lista *l){
    int i;
    if(l->particao == 0 || l->particao >= MAX){
        return 0;
    } else{
        i = l->particao;
        while(i>=0){
            if(l->elementos[i-1] < valor){
               inserirPosicao(valor,i,l);
               return 1;      
        }else{i--;}
    }
  }
}

void exibir(struct lista *l){
    if(l->particao > 0){
    int i;
    for(i=0; i < l->particao; i++){
        printf("[%d]", l->elementos[i]);
    }
    printf("\n");
    }
}

void reverso(struct lista *l){
    if(l->particao > 0){
    int i;
    for(i=l->particao-1;i >= 0;i--){
        printf("[%d]", l->elementos[i]);
    }
    printf("\n");
    }
}

int removerInicio(struct lista *l){
    if(l->particao <= MAX){
    int i;
    for(i=1; i<l->particao; i++){
        l->elementos[i-1] = l->elementos[i];
    }
    l->particao--;
    return 1;
    } else{
        return 0;
    }
}

int removerFim(struct lista *l){
    if(l->particao <= MAX){
    l->particao--;
    return 1;
    } else{
        return 0;
    }
}

int removerPosicao(int posicao,struct lista *l){
    int i;
    if(l->particao > posicao){
    for(i=posicao; i<l->particao; i++){
       l->elementos[i] = l->elementos[i+1];
    }
    l->particao--;
    return 1;
    } else{
        return 0;
    }
}

int removerValor(int valor,struct lista *l){
    int i;
    for(i=0; i<l->particao; i++){
        if(l->elementos[i] == valor){
           removerPosicao(i,l);
           return 1;
        } 
    }if(i >= l->particao){
        return 0;
    }
}

int procurar(int valor,struct lista *l){
    int i;
    for(i=0; i<l->particao; i++){
        if(l->elementos[i] == valor){
            printf("Posicao %d. \n",i);
            return i;
        }
    }if(i >= l->particao){
            return -1;
    }
}

int somatorio(struct lista *l){
    int i,soma = 0;
    for(i=0; i<l->particao; i++){
        soma = soma + l->elementos[i];
    }
    printf("Soma igual a %d. \n", soma);
    return soma;
}

int tamanho(struct lista *l){
    printf("%d elemento(s).\n",l->particao);
    return l->particao;
}

int quadrado(struct lista *l){
    int i;
    for(i=0; i<l->particao; i++){
        l->elementos[i] = l->elementos[i]*l->elementos[i];
    }
}

int primo(int valor){
    int i;
    if(valor == 1){return 0;}
    for(i=2; i<=(valor/2); i++){
        if(valor % i == 0){
            return 0;
        }
    }if(i >= (valor/2)){
        return 1;
    }
}

int qtdPrimos(struct lista *l){
    int i,qtd = 0;
    for(i=0; i<l->particao; i++){
        if(primo(l->elementos[i]) == 1){
            qtd++;
        }
    }
    printf("%d numero(s) primo(s). \n",qtd);
    return qtd;
}
