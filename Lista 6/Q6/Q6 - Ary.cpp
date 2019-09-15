#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
struct Pilha {

	int topo;
	int capa;
	float *pElem;

};

void criarpilha( struct Pilha *p, int c ){

   p->topo = -1;
   p->capa = c;
   p->pElem = (float*) malloc (c * sizeof(float));

}

void empilhar ( struct Pilha *p, char v){

	p->topo++;
	p->pElem [p->topo] = v;

}

int estavazia ( struct Pilha *p ){

   if( p-> topo == -1 )

      return 1;   // true

   else

      return 0;   // false

}

char desempilhar ( struct Pilha *p ){

   char aux = p->pElem [p->topo];
   p->topo--;
   return aux;

}

void hannoi(struct Pilha *p){
    char aux;
    while(estavazia(&Pilha) == false){
        aux = desempilhar();
        if (aux[0] == 1){
            cout<<"Move de "<<aux[1] <<" para "<<aux[2]<<endl;
        }else{
            if(aux[4] == 0){
                aux[0] =- 1;
                aux[2] = 'P3';
                aux[3] = 'P2';
                aux[4] = 1;
                empilha(aux);
                cout<<"Move de "<<aux[1] <<" para "<<aux[2]<<endl;

            }else{
                aux[0] =- 1;
                aux[1] = 'P3'
                aux[2] = 'P2';
                aux[3] = 'P1';
                aux[4] = 0;
                empilha(aux);
            }
        }
    }
}

int main(){
	struct Pilha minhapilha;
	int capacidade, op, cont = 0;
	float valor;
	criarpilha (&minhapilha, 100);
	int n = 5;
    char nome[n] = {3, 'P1', 'P2', 'P3', 0};
    empilhar(&minhapilha, nome);
    hannoi(&minhapilha);
}
