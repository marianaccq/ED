#include <iostream>
using namespace std;

typedef struct s{
    int chave;
	int peso;
	struct s *prox;
} No;

typedef struct Pilha {
	int topo; /* posição elemento topo */
	int capa;
	int *pElem;

} Npilha;

void criarpilha( struct Pilha *p, int c ){

   p->topo = -1;
   p->capa = c;
   p->pElem = new int();
}

float desempilhar ( struct Pilha *p ){
   float aux = p->pElem [p->topo];
   p->topo--;
   return aux;
}
void empilhar ( struct Pilha *p, float v){

	p->topo++;
	p->pElem [p->topo] = v;
}

void adicionarVertice(No *pt, int chave, int peso){
    while(pt->prox != NULL){
        pt = pt->prox;
    }
    No *prox = new No();
    prox->chave = chave;
    prox->peso = peso;
    pt->prox = prox;
}
int main(){
    No *n0 = new No();
    No *n1 = new No();
    No *n2 = new No();
    No *n3 = new No();
    No *n4 = new No();
    No *n5 = new No();
    No *lista[6] = {n0, n1,n2,n3,n4,n5};
    //Liga as vertices do grafo
    adicionarVertice(lista[0], 3, 1);
    adicionarVertice(lista[1], 2, 3);
    adicionarVertice(lista[2], 1, 3);
    adicionarVertice(lista[2], 4, 4);
    adicionarVertice(lista[3], 0, 1);
    adicionarVertice(lista[3], 5, 15);
    adicionarVertice(lista[4], 2, 4);
    adicionarVertice(lista[5], 3, 15);
    //Cria as duas pilhas
    Npilha *pVisita = new Npilha();
    Npilha *pMaior = new Npilha();
	criarpilha (pVisita, 100);
    criarpilha (pMaior, 100);
}
