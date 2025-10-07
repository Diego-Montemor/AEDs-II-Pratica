#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
 

// Cria um novo nó na árvore
struct node* novo_no(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->valor = item;
    temp->esquerda = temp->direita = NULL;
    return temp;
}

// Inserir novo nó com determinado
// valor na árvore binária
struct node* inserir(struct node* node, int valor) {
    // Se a árvore é vazia, então cria um novo nó
    if (node == NULL) {
        return novo_no(valor);
    }
 
    // Caso contrário, faz uma busca pelo local adequado de inserção
    if (valor < node->valor) {
        node->esquerda = inserir(node->esquerda, valor);
    } else if (valor > node->valor) {
        node->direita = inserir(node->direita, valor);
    }
    
    // Retorna o ponteiro para o nó
    return node;
}
 
// Procura por um valor na árvore
struct node* buscar(struct node* root, int valor) {
    // Caso base - a raiz é vazia ou o valor está na raiz
    if (root == NULL || root->valor == valor) {
        return root;
    }

    // Valor é maior que a raiz
    if (root->valor < valor) {
        return buscar(root->direita, valor);
    }

    // Valor é menor que a raiz
    return buscar(root->esquerda, valor);
}

struct node* busca_pai(struct node* raiz, struct node* n){
    if(raiz == n)
        return NULL;
    
    if((raiz->esquerda != NULL && raiz->esquerda == n) ||
    (raiz->direita != NULL && raiz->direita == n))
        return raiz;
    
    if(raiz->valor > n->valor)
        return busca_pai (raiz->esquerda, n);
    else
        return busca_pai (raiz->direita, n);
}

struct node* remove_no(struct node* raiz, int valor){
    struct node* n = buscar(raiz, valor);
    //printf("busca funcionou!\n");
    if(n){
        //printf("no encontrado!\n");
        struct node* pai = busca_pai(raiz, n);
        //printf("pai funcionou!\n");

        if(pai){
            //printf("pai encontrado!\n");
           if(pai->direita == n)
                pai->direita = n->direita;
            else
                pai->esquerda = n->direita;
        }else{
            //printf("pai não encontrado!\n");

            struct node* p = raiz;
            struct node* q = raiz->esquerda;

            while(q->direita != NULL){
                p = q;
                q = q->direita;
            }

            p->direita = q->esquerda;
            q->esquerda = raiz->esquerda;
            q->direita = raiz->direita;

            return q;
        }
        if(n->esquerda != NULL){
            struct node* tmp = n->direita;
            while(tmp->esquerda != NULL){
                tmp = tmp->esquerda;
            }
            tmp->esquerda = n->esquerda;
        }
    }
    return raiz;
}
 
int main() {
    // Define a árvore como uma estrutura vazia
    struct node* root = NULL;

    // Insere o nó inicial (raiz)
    root = inserir(root, 50);

    // Insere outros nós
    inserir(root, 30);
    inserir(root, 20);
    inserir(root, 40);
    inserir(root, 70);
    inserir(root, 60);
    inserir(root, 80);
 
    // Valor a ser buscado
    int valor = 6;
 
    // Buscando na árvore
    if (buscar(root, valor) == NULL) {
        printf("%d não encontrado\n", valor);
    } else {
        printf("%d encontrado\n", valor);
    }
 
    // Novo valor a ser buscado
    valor = 60;
 
    // Buscando na árvore
    if (buscar(root, valor) == NULL) {
        printf("%d não encontrado\n", valor);
    } else {
        printf("%d encontrado\n", valor);
    }

    remove_no(root, valor);

    if (buscar(root, valor) == NULL) {
        printf("%d não encontrado\n", valor);
    } else {
        printf("%d encontrado\n", valor);
    }

        valor = 30;
 
    // Buscando na árvore
    if (buscar(root, valor) == NULL) {
        printf("%d não encontrado\n", valor);
    } else {
        printf("%d encontrado\n", valor);
    }

    remove_no(root, valor);

    if (buscar(root, valor) == NULL) {
        printf("%d não encontrado\n", valor);
    } else {
        printf("%d encontrado\n", valor);
    }

    return 0;
}