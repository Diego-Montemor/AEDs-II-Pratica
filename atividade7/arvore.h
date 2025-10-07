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
void preOrdem(struct node* no);
void posOrdem(struct node* no);
int contar(struct node* raiz);
void CriaVetor(struct node* raiz, int *vet, int *idx);
struct node* RecriaArvore(int *vet, int ini, int fim);
struct node* balancear_arvore(struct node* raiz);
void liberar_arvore(struct node* raiz);

#endif // _H_ARVORE