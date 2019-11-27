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

void BP(No **lista, bool *flag, int vert, int dest, bool &caminho){
    flag[vert] = 1;
    No *aux = lista[vert]->next;
    cout<<"Entrou"<<endl;
    while(aux!=lista[vert]){
        int w = aux->chave;
        if(!flag[w]){
            if(w == dest){
                caminho = 1;
            }
            cout<<lista[vert]->chave<<"-"<<lista[w]->chave<<" , tipo I"<<endl;
            aux->visita=1;
            flag[w]=1;
            BP(lista,flag,w,dest,caminho);

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

    inserir(lista[0],1);inserir(lista[0],2);inserir(lista[0],7);inserir(lista[1],3);inserir(lista[1],4);
    inserir(lista[3],5);inserir(lista[4],5);inserir(lista[5],6);inserir(lista[7],8);inserir(lista[8],9);

    inserir(lista[1],0);inserir(lista[2],0);inserir(lista[7],0);inserir(lista[3],1);inserir(lista[4],1);
    inserir(lista[5],3);inserir(lista[5],4);inserir(lista[6],5);inserir(lista[8],7);inserir(lista[9],8);

    bool flag[10];
    for(int i=0;i<10;i++){
        flag[i]=0;
    }
    bool caminho = 0;

    int origem,destino;
    origem = 2;
    destino = 8;

    BP(lista,flag,origem,destino,caminho);

    cout<<caminho<<endl;
    return 0;
}
