#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct vetAr{
    int ar1;
    int ar2;
    int peso;
    int tipo;
}va;

void uniao(int x, int y, int v[], int n){
    int rep = v[y];
    for(int i = 0; i < n; i++){
        if(v[i] == rep){
            cout<<"Unindo "<<i<<" e "<<v[x]<<endl;
            v[i] = v[x];
        }
    }
}

bool same_set(int x, int y, int v[]){
    if(v[x] == v[y]){
        return true;
    }else{
        return false;
    }
}

void inserir(vetAr &par, int x, int y, int peso, int tipo){
    par.ar1=x;
    par.ar2=y;
    par.peso=peso;
    par.tipo = tipo;
}

void printArestas(vetAr *grafo, int n){
    for(int i=0;i<n;i++){
        cout<<grafo[i].ar1<<"-"<<grafo[i].ar2<<", P = "<<grafo[i].peso<<endl;
    }
}

void quickSortmen(vector<vetAr> grafo, int p,  int r){
    if (p<r){
          vetAr temp;
          int x=grafo[r].peso;
          int i=p-1;
        for(  int j=p;j<r;j++){
            if(grafo[j].peso<x){
                i++;
                temp=grafo[i];
                grafo[i]=grafo[j];
                grafo[j]=temp;
            }
        }

        temp=grafo[i+1];
        grafo[i+1]=grafo[r];
        grafo[r]=temp;

        int q=i+1;

        quickSortmen(grafo,p,q-1);
        quickSortmen(grafo,q+1,r);

    }
}

vector<vetAr> agmTipo(vetAr *part, int m, int n, bool &sucesso){
    vector <vetAr> T;
    vector <vetAr> Verm;
    int set[n];
    for(int i=0;i<n;i++){
        set[i]=i;
    }

    //////Tipo azul
    for(int i=0;i<m;i++){
        if(part[i].tipo == 0){
            T.push_back(part[i] );
            uniao( part[i].ar1,part[i].ar2,set,n );
        }
        if(part[i].tipo == 1){
            Verm.push_back(part[i] );
        }
    }

    quickSortmen(Verm,0,Verm.size()-1);

    /////Tipo Vermelho
    for(int i=0; i<Verm.size() ;i++){
        if(!same_set( Verm[i].ar1,Verm[i].ar2,set )){
            uniao( Verm[i].ar1, Verm[i].ar2 ,set,n);
            T.push_back(Verm[i]);
        }
    }


    ////Todos ligados
    sucesso = 1;
    int comp = set[0];
    for(int i=0;i<n;i++){
        if(set[i]!=comp){
            sucesso = 0;
            break;
        }
    }
    return T;

}

int main()
{
    vetAr part[10];

    inserir(part[0],0,1,20,1);    inserir(part[1],0,2,22,2);    inserir(part[2],0,3,15,2);    inserir(part[3],0,4,28,2);    inserir(part[4],1,2,13,0);
    inserir(part[5],1,3,19,2);    inserir(part[6],1,4,26,2);    inserir(part[7],2,3,11,0);    inserir(part[8],2,4,12,2);    inserir(part[9],3,4,28,0);

    bool sucesso = 1;
    vector<vetAr> resposta = agmTipo(part,10,5,sucesso);

    for(int i=0;i<resposta.size();i++){
        cout<<resposta[i].ar1<<"-"<<resposta[i].ar2<<", P="<<resposta[i].peso<<endl;
    }

    return 0;
}
