#ifndef _H_PILHA
#define _H_PILHA

struct pilha* criar_pilha(int tamanho);
bool ehVazia(struct pilha* pilha);
void push(struct pilha* pilha, int item);
struct no* pop(struct fila* fila);
struct no* obtem_elemento(struct pilha* pilha);

#endif // _H_PILHA