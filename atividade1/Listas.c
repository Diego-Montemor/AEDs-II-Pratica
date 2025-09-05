#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "lista.h" 

struct node {
    int data;
    struct node *next;
}*p,*tmp,*tmp1;

void inserir_fim(int elemento) {
    tmp = p;
    tmp1 = (struct node*) malloc (sizeof(struct node));
    tmp1->data=elemento;
    tmp1->next=NULL;
    if (p == NULL) {
        p = tmp1;
    } else {
        while (tmp->next!=NULL) {
            tmp = tmp->next;
        }
        tmp->next = tmp1;
    }
 }

void inserir_inicio(int elemento) {
	 tmp = p;
	 tmp1 = (struct node*) malloc (sizeof(struct node));
	 tmp1->data=elemento;
	 tmp1->next = p;
	 p=tmp1;
}

void apagar(int ele) {
    tmp = p;
	struct node *pre=tmp;
	while (tmp != NULL) {
		if (tmp->data==ele) {
            if (tmp == p) {
                p = tmp->next;
			    free(tmp);
			    return;
			} else {
                pre->next=tmp->next;
			    free(tmp);
			    return;
			}
		} else {
            pre = tmp;
		    tmp = tmp->next;
		}
	}
	printf("\n Valor não encontrado! ");
 }
 
void apagar_inicio() {	
	tmp = p;
	if (p == NULL) {
		printf("\n Nenhum elemento deletado ");
    } else {
		printf("\nElemento deletado - %d", p->data);
        p = p->next;
        free(tmp);
	}
 }
 
void apagar_fim() {	
	tmp=p;
	struct node* pre;
	if(p == NULL) {
		printf("\n Nenhum elemento deletado ");
    } else if (p->next == NULL) {
		printf("\nElemento deletado - %d", p->data);
		p = NULL;
	} else {
		while (tmp->next != NULL) {
			pre=tmp;
			tmp=tmp->next;
		}
		pre->next=NULL;
        free(pre);
		printf("\nElemento deletado - %d", tmp->data);
	}
}

bool ehVazia() {
    if (p == NULL) {
        return (1);
    } else {
        return (0);
    }
}
void imprimir() {
	tmp = p;
 	while (tmp != NULL) {
        printf("\n %d",tmp->data);
	 	tmp = tmp->next;
	}
}

int obter_primeiro(void) {
    tmp = p;
	if (p == NULL) {
		printf("\n Nenhum elemento encontrado ");
    } else {
		return (p->data);
	}
}

int obter_ultimo(void) {
    tmp = p;
	struct node* pre;
	if (p == NULL) {
		printf("\n Nenhum elemento encontrado ");
        return (0);
    } else if (p->next==NULL) {
		return(p->data);
	} else {
		while (tmp->next!=NULL) {
			pre=tmp;
			tmp=tmp->next;
		}
		pre->next=NULL;
		return(tmp->data);
	}
}

void inserir_posicao(int valor,int posicao){
    if(p != NULL){
        int i = 0;
        struct node *prev;
        tmp = p;
        while(tmp->next != NULL && i < posicao - 1){
            i = i + 1;
            prev = tmp;
            tmp = tmp->next;
        }
        if(posicao == 1){
            printf("O elemento foi inserido no inicio da lista");
            inserir_inicio(valor);        
        }else{
            printf("o elemento foi posicionado na posicao %d",posicao);
            tmp1 = (struct node*) malloc (sizeof(struct node));
            tmp1->data = valor;
            tmp1->next = tmp;
            prev->next = tmp1;
        }
    }else inserir_inicio(valor);
};

void remover_posicao(int posicao){
    if(p != NULL){
    int i = 0;
    tmp = p;
    while(tmp->next != NULL && i < posicao - 1){
        i = i + 1;
        tmp1 = tmp;
        tmp = tmp->next;
    }
    if(posicao == 1){
        p = p->next;
        tmp1->next = NULL;
    }else{
        tmp1->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }   
    }else printf("A lista esta vazia");
}

int buscar_posicao(int posicao){
    if(p != NULL){
        int i = 1;
        tmp = p;
        while(tmp->next != NULL && i < posicao){
            i++;
            tmp = tmp->next;
        }
        if(i == posicao){
            return tmp->data;
        }else if(posicao > i) return 0;
    }else return 0;
}

int main() { 
  int val, n;
  p = NULL;
  do {
    printf("\n************************* MENU ************************");
	printf("\n1.Inserir no fim");
	 printf("\n2.Inserir no início");
	 printf("\n3.Apagar um elemento em particular");
	 printf("\n4.Apagar do início");
	 printf("\n5.Apagar do fim");
	 printf("\n6.Imprimir lista");
	 printf("\n7.É vazia?");
     printf("\n8.Obter primeiro");
     printf("\n9.Obter último");
     printf("\n10.Inserir na posicao");
     printf("\n11.Remover na posicao");
     printf("\n12.Buscar o valor na posicao");
     printf("\n0.Sair");
	 printf("\nEntre sua opção : ");
	 scanf("%d",&n);
	 switch(n) {
        case 1: printf("\nDigite o valor ");
			    scanf("%d",&val);
			    inserir_fim(val);
			    break;
		 case 2: printf("\nDigite o valor ");
			    scanf("%d",&val);
			    inserir_inicio(val);
			    break;
		 case 3: printf("\nDigite o valor ");
			    scanf("%d",&val);
			    apagar(val);
			    break;
		 case 4: 
			    apagar_inicio();
			    break;
		 case 5: 
			    apagar_fim();
			    break;
		 case 6: imprimir();
		 	    break;
		 case 7: if (ehVazia() == 1) {
                    printf("\nLista vazia");
                } else {
                    printf("\nLista não vazia");
                }
                break;
        case 8: val = obter_primeiro();
                if (val != 0) {
                    printf("%d", val);
                }
		 	    break;
        case 9: val = obter_ultimo();
                if (val != 0) {
                    printf("%d", val);
                }
		 	    break;
        case 10:{
                int valor, posicao;
                printf("Digite um valor para ser incerido na posicao desejada:");
                scanf("%d",&valor);
                printf("Digite a posicao desejada: ");
                scanf("%d", &posicao);
                inserir_posicao(valor,posicao);
                }
                break;
        case 11:{
                int posicao;
                printf("Digite a posicao que deve ser removida: ");
                scanf("%d", &posicao);
                remover_posicao(posicao);
        }
        break; 
        case 12:{
                int posicao, valor;
                printf("Digite a posicao que deve ser buscada");
                scanf("%d", &posicao);
                valor = buscar_posicao(posicao);
                if(valor != 0) printf("%d",valor);
                else printf("nao foi encontrado nenhum valor nessa posicao");
        }
        break;
        case 0: exit(0);
		 	    break;
		default: printf("\n Opção errada!");
		 	    break;
		}
	} while(1);

 }