#include<stdio.h>
#include<stdlib.h>
#include"lista_sequencial.h"

int main(int argc, char *argv){

    int opcao = 16, valor, posicao;
    struct lista *l;
    l = (struct lista *)malloc(sizeof(struct lista));
    inicializar(l);

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
    printf("saber a quantidade de elementos da lista,digite 13;\n");
    printf("transformar todos os elementos da lista em seus quadrados,digite 14;\n");
    printf("saber a quantidade de numeros primos da lista,digite 15.\n");
    printf("Caso queira encerrar a execucao,digite 0.\n");
    
    while(opcao != 0){

        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Digite o numero:\n");
                scanf("%d", &valor);
                inserirInicio(valor,l);
                break;
            case 2:    
                printf("Digite o numero:\n");
                scanf("%d", &valor);
                inserirFim(valor,l);
                break;
            case 3:
                printf("Digite o numero:\n");
                scanf("%d", &valor);
                printf("Digite a posicao:\n");
                scanf("%d", &posicao);
                inserirPosicao(valor,posicao,l);
                break;  
            case 4:
                printf("Digite o numero:\n");
                scanf("%d", &valor);
                inserirOrdem(valor,l);
                break; 
            case 5:
                exibir(l);
                break;
            case 6:
                reverso(l);
                break;
            case 7:
                removerInicio(l);
                break;
            case 8:
                removerFim(l);
                break;
            case 9:
                printf("Digite a posicao:\n");
                scanf("%d", &posicao);
                removerPosicao(posicao,l);
                break;
            case 10:
                printf("Digite o numero:\n");
                scanf("%d", &valor);
                removerValor(valor,l);
                break;      
            case 11:
                printf("Digite o numero:\n");
                scanf("%d", &valor);
                procurar(valor,l);
                break; 
            case 12:
                somatorio(l);
                break;
            case 13:
                tamanho(l);
                break;
            case 14:
                quadrado(l);
                break;
            case 15:
                qtdPrimos(l);
                break;
            case 0:
                break;                                         
        }
    }
    
    exit(0);

}