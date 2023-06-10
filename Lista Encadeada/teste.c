#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

int main(int argc, char *argv){

       lista l = (lista)malloc(sizeof(no));
       l = NULL;

       int opcao = 16, valor, posicao;

       printf("Caso queira inserir um numero no inicio,digite 1;\n");
       printf("inserir um numero no fim,digite 2;\n");
       printf("inserir um numero em uma determinada posicao,digite 3;\n");
       printf("inserir um numero em ordem,digite 4;\n");
       printf("exibir a lista,digite 5;\n");
       printf("exibir a lista ao contrario,digite 6;\n");
       printf("remover o primeiro numero da lista,digite 7;\n");
       printf("remover o ultimo numero da lista,digite 8;\n");
       printf("remover um numero de uma posicao especifica,digite 9;\n");
       printf("remover um numero especifico,digite 10;\n");
       printf("procurar a posicao de um numero especifico,digite 11;\n");
       printf("somar todos os elementos da lista,digite 12;\n");
       printf("saber o tamanho da lista,digite 13;\n");
       printf("transformar todos os elementos da lista em seus quadrados,digite 14;\n");
       printf("saber a quantidade de numeros primos da lista,digite 15.\n");
       printf("Caso queira encerrar a execucao,digite 0.\n");
    
       while(opcao != 0){
        
        printf("\n");
        printf("Digite o numero referente ao processo que quer fazer:\n");
        scanf("%d", &opcao);

        switch(opcao){

            case 1:
                printf("Digite o numero:\n");
                scanf("%d", &valor);
                l = inserir_inicio(l, valor);
                break;

            case 2:    
                printf("Digite o numero:\n");
                scanf("%d", &valor);
                l = inserir_fim(l, valor);
                break;

            case 3:
                printf("Digite o numero:\n");
                scanf("%d", &valor);
                printf("Digite a posicao:\n");
                scanf("%d", &posicao);
                l = inserir_posicao(l, posicao, valor);
                break;

            case 4:
                printf("Digite o numero:\n");
                scanf("%d", &valor);
                l = inserir_ordem(l, valor);
                break;

            case 5:
                exibir(l);
                break;

            case 6:
                exibir_reversa(l);
                printf("\n");
                break;

            case 7:
                l = remover_inicio(l);
                break;

            case 8:
                l = remover_fim(l);
                break;

            case 9:
                printf("Digite a posicao:\n");
                scanf("%d", &posicao);
                l = remover_posicao(l, posicao);
                break;

            case 10:
                printf("Digite o numero:\n");
                scanf("%d", &valor);
                l = remover_valor(l, valor);
                break;

            case 11:
                printf("Digite o numero:\n");
                scanf("%d", &valor);
                procurar_posicao(l, valor);
                break;

            case 12:
                somatorio(l);
                break;

            case 13:
                tamanho(l);
                break;

            case 14:
                l = lista_quadrada(l);
                break;

            case 15:
                quantidade_primos(l);
                break;

            case 0:
                break;   

        }
    }

       exit(0);

}