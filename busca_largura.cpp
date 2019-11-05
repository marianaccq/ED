#include <iostream>
using namespace std;

typedef struct s{
    int chave;
	int peso;
	struct s *prox;
} No;

typedef struct Fila {

	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens;

}Nof;

void criarFila( struct Fila *f, int c ) {

	f->capacidade = c;
	f->dados = new float();
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0;

}

void inserir(struct Fila *f, int v) {

	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v;
	f->nItens++;

}

int remover( struct Fila *f ) {
	int temp = f->dados[f->primeiro++];
	if(f->primeiro == f->capacidade)
		f->primeiro = 0;
	f->nItens--;
	return temp;
}

int estaVazia( struct Fila *f ) {
	return (f->nItens==0);
}

bool marca[6];

void printMarca(){
    for(int i = 0; i<6; i++){
        cout<<marca[i]<<" ";
    }
    cout<<endl;
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

void Bl(No *lista[6], int chave, Nof *fila){
    printMarca();
    cout<<"MARCOU "<<chave<<endl;
    marca[chave] = 1;
    inserir(fila, chave);
    while(!estaVazia(fila)){
        int chave_fila = remover(fila);
        No *pt = lista[chave_fila];
        while(pt!= NULL){
            if(marca[pt->chave] != 1){
                marca[pt->chave] = 1;
                inserir(fila, pt->chave);
                printMarca();
                cout<<"MARCOU "<<pt->chave<<endl;
            }
            pt = pt->prox;
        }
    }
}

int main(){
    //Cria a Fila
    Nof *fila = new Nof();
    criarFila(fila, 100);
    No *n0 = new No();
    No *n1 = new No();
    No *n2 = new No();
    No *n3 = new No();
    No *n4 = new No();
    No *n5 = new No();
    No *lista[6] = {n0, n1,n2,n3,n4,n5};
    //Liga as vertices do grafo
    adicionarVertice(lista[0], 3, 1);
    adicionarVertice(lista[0], 1, 4);
    adicionarVertice(lista[1], 2, 3);
    adicionarVertice(lista[1], 0, 4);
    adicionarVertice(lista[2], 1, 3);
    adicionarVertice(lista[2], 4, 4);
    adicionarVertice(lista[3], 0, 1);
    adicionarVertice(lista[3], 5, 15);
    adicionarVertice(lista[4], 2, 4);
    adicionarVertice(lista[5], 3, 15);
    lista[0]->chave = 0;
    lista[1]->chave = 1;
    lista[2]->chave = 2;
    lista[3]->chave = 3;
    lista[4]->chave = 4;
    lista[5]->chave = 5;
    Bl(lista, 0, fila);
}
