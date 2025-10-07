#ifndef _H_ARVORE
#define _H_ARVORE

struct node {
    int valor;
    struct node *esquerda, *direita;
};

struct node* novo_no(int item);
struct node* inserir(struct node* node, int valor);
struct node* buscar(struct node* root, int valor);
struct node* busca_pai(struct node* raiz, struct node* n);
struct node* remove_no(struct node* raiz, int valor);

#endif // _H_ARVORE