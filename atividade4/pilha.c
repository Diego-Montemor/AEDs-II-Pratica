#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>
#include "pilha.h"

struct no{
    int valor;
    struct no* prox;
}*tmp;

struct fila { 
	struct no* inicio, *fim; 
	int tamanho; 
	int* items; 
}; 


struct fila* criar_fila() { 
	// Aloca a estrutura de dados pilha
    struct fila* fila = (struct fila*)malloc(sizeof(struct fila)); 
    fila->tamanho = 0;
    fila->inicio = NULL;
    fila->fim = NULL;
    // Retorna a pilha
	return fila; 
} 


bool ehVazia(struct fila* fila) { 
   
    if (fila->inicio == NULL) {
        return (true);
    } 
    return (false);
} 

void push(struct fila* fila, int item) { 
    tmp = (struct no*) malloc(sizeof(struct no));
    tmp->valor = item;
    tmp->prox = NULL;
    if (ehVazia(fila)) { 
        fila->inicio = tmp;
        fila->fim = tmp;
        fila->tamanho++;
        return;
    }
    fila->fim->prox = tmp;
    fila->fim = tmp;
    fila->tamanho++; 
} 


struct no* pop(struct fila* fila) { 
    if (ehVazia(fila)) {
        printf("\nFila vazia. Impossível remover elementos");
        return NULL; 
    }
    struct no* item = fila->inicio;
    if (fila->inicio == fila->fim) { // Último elemento removido
       
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->tamanho--;
    } else {
        fila->inicio = fila->inicio->prox;
        fila->tamanho--;
    }
    return item;
} 

struct no* obtem_elemento(struct fila* fila) { 
	
    if (ehVazia(fila)) {// Se a fila estiver vazia, não tem como obter nenhum elemento
		printf("\nFila vazia. Impossível obter elementos");
        return -1; 
    }
    
	return fila->inicio; // Retorna o elemento do início da fila
} 


int main() { 
    int val, n;
    bool aux;
    struct fila* fila = criar_fila(); 
    do {
        printf("\n************************* MENU ************************");
	    printf("\n1. Push");
	    printf("\n2. Pop");
	    printf("\n3. Obtém elemento");
	    printf("\n4. Pilha vazia?");
	    printf("\n5. Sair");
	    printf("\n Digite sua escolha : ");
	    scanf("%d",&n);
	    switch(n) {
            case 1: 
		        printf("\nDigite o valor ");
                scanf("%d",&val);
                push(fila , val);
                break;
            case 2: 
                printf("\nElemento retirado : %d",pop(fila)->valor);
                break;
            case 3: 
                printf("\nElemento no inicio: %d",obtem_elemento(fila)->valor);
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
                return (1);
                break;
            default: printf("\nOpção errada!");
                break;
        }
	} while(1);
    
    return (0);
 }




