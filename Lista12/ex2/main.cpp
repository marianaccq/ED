#include <iostream>

using namespace std;

typedef struct No
{
  int chave;
  int peso;
  struct No *next;
} TipoNo;

void inserir(No *cabeca, int novoVaor, int peso){
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
        novoNo->peso = peso;
        pont->next = novoNo;
    }
}

void printDireto(No *cabeca){
    cout<<cabeca->chave<<" :";
    No *aux = cabeca->next;
    while (aux!=cabeca){
        cout<<aux->chave<<"P"<<aux->peso<<"->";
        aux = aux->next;
    }
    cout<<endl;
}

bool BellFord(No **grafo,int inicio, int n, int *d, int *rot){
    for(int i=0;i<n;i++){
        d[i] = 9999;
        rot[i] = -1;
    }
    d[inicio] = 0;
    rot[inicio] = inicio;
    cout<<"Iniciou"<<endl;
    bool troca = true;
    while(troca){
        troca=false;
        for(int i=0;i<n;i++){
            No *aux = grafo[i]->next;
            while(aux!=grafo[i]){
                int u = grafo[i]->chave;
                int v = aux->chave;
                if(d[v] > (d[u]+aux->peso)){
                    troca = true;
                    d[v] = d[u]+aux->peso;
                    rot[v] = u;
                }
                aux=aux->next;
            }
        }
    }
    for(int i=0;i<n;i++){
        No *aux = grafo[i]->next;
        while(aux!=grafo[i]){
            int u = grafo[i]->chave;
            int v = aux->chave;
            if(d[v]>(d[u]+aux->peso)){
                return false;
            }
            aux=aux->next;

        }
    }
    return true;
}

int main()
{

    int n = 5;
    No **grafo = new No*[n];
    for(int i=0;i<n;i++){
        grafo[i] = new No();
        grafo[i]->chave = i;
        grafo[i]->next = grafo[i];
    }

    inserir(grafo[0],1,6); inserir(grafo[0],3,7);inserir(grafo[1],2,5);inserir(grafo[1],3,8);inserir(grafo[1],4,-4);
    inserir(grafo[2],1,-2);inserir(grafo[3],2,-3);inserir(grafo[3],4,2);inserir(grafo[4],0,9);inserir(grafo[4],2,7);

    for(int i=0;i<n;i++){
        printDireto(grafo[i]);
    }

    int d[n], rot[n];

    bool BMF = BellFord(grafo,0,n,d,rot);

    for(int i=0;i<n;i++){
        cout<<d[i]<<"-"<<rot[i]<<endl;
    }
    cout<<BMF<<endl;

    return 0;
}
