#include <iostream>

using namespace std;

typedef struct No
{
  int chave;
  bool visita = 0;
  struct No *next;
} TipoNo;

void inserir(No *cabeca, int novoVaor){
    No *ant = cabeca->next;
    No *pont = cabeca;
    bool naLista=false;
    while(ant!=cabeca){
        if(ant->chave == novoVaor){
            naLista = true;
        }
        ant=ant->next;
        pont = pont->next;
    }
    if(naLista){
        cout<<"Elemento "<<novoVaor<<" encontra-se na lista"<<endl;
        return;
    }
    No *novoNo = new No();
    if (novoNo!=nullptr){
        novoNo->chave = novoVaor;
        novoNo->next = cabeca;
        pont->next = novoNo;
    }
}

void inserirD(int x, int y, No **lista){
    inserir(lista[x],y);
    inserir(lista[y],x);
}

void printDireto(No *cabeca){
    cout<<cabeca->chave<<" :";
    No *aux = cabeca->next;
    while (aux!=cabeca){
        cout<<aux->chave<<"->";
        aux = aux->next;
    }
    cout<<endl;
}

void BP(No **lista, bool *flag, int vert){
    flag[vert] = 1;
    No *aux = lista[vert]->next;
    while(aux!=lista[vert]){
        int w = aux->chave;
        if(!flag[w]){
            cout<<lista[vert]->chave<<"-"<<lista[w]->chave<<" , tipo I"<<endl;
            aux->visita=1;
            flag[w]=1;
            BP(lista,flag,w);
        }
        else{
            if(!aux->visita){
                cout<<lista[vert]->chave<<"-"<<lista[w]->chave<<" , tipo II"<<endl;
                aux->visita = 1;
            }
        }
        aux=aux->next;
    }
}


int main()
{
    int vertices = 10;
    No **lista;
    lista= new No*[vertices];
    if(lista == nullptr){
        cout<<"Grafo nao criado"<<endl;
        exit(1);
    }
    for(  int i=0;i<vertices;i++){
        lista[i] = new No();
        if(lista[i] == nullptr){
            cout<<"lista "<<i<<" nao criada"<<endl;
            exit(2);
        }
        lista[i]->chave = i;
        lista[i]->next = lista[i];
    }

    inserir(lista[0],1);inserir(lista[1],2);inserir(lista[2],4);inserir(lista[3],4);
    inserir(lista[3],2);inserir(lista[4],0);inserir(lista[5],6);

    bool flag[vertices];
    for(int i=0;i<vertices;i++){
        flag[i]=0;
    }

    bool conexo = 1;

    BP(lista,flag,0);

    for(int i=0;i<vertices;i++){
        if(!flag[i]){
            conexo = 0;
            break;
        }
    }

    cout<<conexo<<endl;

    return 0;
}
