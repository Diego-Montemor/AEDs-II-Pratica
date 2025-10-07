#include <stdio.h>
#include <stdlib.h>
//#include "arvore.h"

struct node {
    int valor;
    struct node *esquerda, *direita;
};

// Cria um novo nó na árvore
struct node* novo_no(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->valor = item;
    temp->esquerda = temp->direita = NULL;
    return temp;
}

void preOrdem(struct node* no){
    if(no == NULL){
        return;
    }
    printf("%d\n", no->valor);
    preOrdem(no->esquerda);
    preOrdem(no->direita);
};

void emOrdem(struct node* no){
    if(no == NULL){
        return;
    }
    emOrdem(no->esquerda);
    printf("%d\n", no->valor);
    emOrdem(no->direita);
};

void posOrdem(struct node* no){
    if(no == NULL){
        return;
    }
    posOrdem(no->esquerda);
    posOrdem(no->direita);
    printf("%d\n", no->valor);
};
 
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

int contar(struct node* raiz){
    if(raiz == NULL){
        return 0;
    }
    return 1 + contar(raiz->esquerda) + contar(raiz->direita);
}

void CriaVetor(struct node* raiz, int *vetor, int *i){
    if(raiz == NULL){
        return;
    }
    CriaVetor(raiz->esquerda, vetor, i);
    vetor[(*i)++] = raiz->valor;
    CriaVetor(raiz->direita, vetor, i);
}

// usa uma função recursiva para montar a nova arvore usando uma função parecida com a busca binaria
struct node* RecriaArvore(int *vet, int inicio, int fim){ 
    if(inicio > fim){
        return NULL;
    }

    int meio = (inicio + fim) / 2;
    struct node* raiz = novo_no(vet[meio]);

    raiz->esquerda = RecriaArvore(vet, inicio, meio - 1);
    raiz->direita  = RecriaArvore(vet, meio + 1, fim);

    return raiz;
}

void liberar_arvore(struct node* raiz){ // apaga a arvore antiga
    if(!raiz){
        return;
    }
    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);
    free(raiz);
}

struct node* balancear_arvore(struct node* raiz){
    if(raiz == NULL){
        return NULL;
    }
    int n = contar(raiz);
    int *vetor = (int*) malloc (sizeof(int) * n);
    int i = 0;

    CriaVetor(raiz, vetor, &i);
    // Libera árvore antiga para evitar lotar a memoria
    liberar_arvore(raiz);
    struct node* nova = RecriaArvore(vetor, 0, n - 1);

    free(vetor);
    return nova;
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
    inserir(root, 90);
    inserir(root, 100);
    inserir(root, 110);
    inserir(root, 130);
    inserir(root, 120);
    inserir(root, 125);
    inserir(root, 121);
    inserir(root, 132);
    inserir(root, 140);
    // Valor a ser buscado
    int valor = 6;

    //preOrdem(root);
    //posOrdem(root);


    printf("\n-----------\n");

    preOrdem(root);

    root = balancear_arvore(root);

    printf("\n-----------\n");

    preOrdem(root);
 
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