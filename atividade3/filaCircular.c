#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>
#include "pilha.h"

struct fila { 
	int inicio, fim; 
	int tamanho; 
	int* items; 
}; 

struct fila* criar_fila(int tamanho) { 
	// Aloca a estrutura de dados pilha
    struct fila* fila = (struct fila*)malloc(sizeof(struct fila)); 
	// Armazena o tamanho que ela foi criada
    fila->tamanho = tamanho; 
    // Diz que não existe nenhum elemento no topo
	fila->inicio = -1;
    fila->fim = -1; 
    // Aloca o vetor de items utilizando o tamanho passado para a função
	fila->items = (int*)malloc(fila->tamanho * sizeof(int)); 
    // Retorna a pilha
	return fila; 
} 

bool ehCheia(struct fila* fila) { 
    int n = (fila->fim + 1) % fila->tamanho;
	if (fila->inicio == n) {
        return (true);
    }
    // Caso contrário, ela não está cheia
    return (false);
} 

bool ehVazia(struct fila* fila) { 
	// Se o topo == -1, então a pilha é vazia
   
    if (fila->inicio == -1) { // Verificar que isto é verdade na criação da pilha
        return (true);
    } 
    return (false);
} 

void push(struct fila* fila, int item) { 
    if (ehCheia(fila)) {
        printf("\nFila cheia. Impossível inserir elementos");
        return; 
    } else if (ehVazia(fila)) { 
        fila->inicio = 0;
        fila->fim = 0;
        fila->items[fila->fim] = item; // Insere o primeiro elemento
        return;
    }
    fila->fim = (fila->fim + 1) % fila->tamanho;
    fila->items[fila->fim] = item; 
} 


int pop(struct fila* fila) { 
    if (ehVazia(fila)) {
        printf("\nFila vazia. Impossível remover elementos");
        return -1; 
    }
    int item = fila->items[fila->inicio];
    if (fila->inicio == fila->fim) { // Último elemento removido
       
        fila->inicio = -1;
        fila->fim = -1;
    } else {
        fila->inicio = (fila->inicio + 1) % fila->tamanho;
    }
    return item;
} 

int obtem_elemento(struct fila* fila) { 
	
    if (ehVazia(fila)) {// Se a fila estiver vazia, não tem como obter nenhum elemento
		printf("\nFila vazia. Impossível obter elementos");
        return -1; 
    }
    
	return fila->items[fila->inicio]; // Retorna o elemento do início da fila
} 


int main() { 
    int val, n;
    bool aux;
    // Cria pilha com 5 posições
    struct fila* fila = criar_fila(5); 
    do {
        printf("\n************************* MENU ************************");
	    printf("\n1. Push");
	    printf("\n2. Pop");
	    printf("\n3. Obtém elemento");
	    printf("\n4. Pilha vazia?");
        printf("\n5. Pilha cheia?");
	    printf("\n6. Sair");
	    printf("\n Digite sua escolha : ");
	    scanf("%d",&n);
	    switch(n) {
            case 1: 
		        printf("\nDigite o valor ");
                scanf("%d",&val);
                push(fila , val);
                break;
            case 2: 
                printf("\nElemento retirado : %d",pop(fila));
                break;
            case 3: 
                printf("\nElemento do topo: %d",obtem_elemento(fila));
                break;
            case 4: 
                aux = ehVazia(fila);
                if (aux) {
                    printf("\nPilha vazia");
                } else {
                    printf("\nPilha não está vazia");
                }
                break;
            case 5: 
                aux = ehCheia(fila);
                if (aux) {
                    printf("\nPilha cheia");
                } else {
                    printf("\nPilha não está cheia");
                }
                break;         
            case 6:
                return (1);
                break;
            default: printf("\nOpção errada!");
                break;
        }
	} while(1);
    
    return (0);
 }




