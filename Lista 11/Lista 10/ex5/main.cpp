#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct vetAr{
    int ar1;
    int ar2;
    int peso;
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

void inserir(vetAr &par, int x, int y, int peso){
    par.ar1=x;
    par.ar2=y;
    par.peso=peso;
}

void printArestas(vetAr *grafo, int n){
    for(int i=0;i<n;i++){
        cout<<grafo[i].ar1<<"-"<<grafo[i].ar2<<", P = "<<grafo[i].peso<<endl;
    }
}

void quickSortmen(vetAr *grafo,   int p,  int r){
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
vector<vetAr> kruskalmen(vetAr* grafo, int m, int n){
    quickSortmen(grafo,0,m-1);
    vector <vetAr> T;
    T.push_back(grafo[0]);
    int set[n];
    printArestas(grafo,m);
    for(int i = 0;i<n;i++){
        set[i]=i;
    }
    uniao(grafo[0].ar1,grafo[0].ar2,set,n);

    for(int i = 0;i<n;i++){
        cout<<set[i]<<" ";
    }

    cout<<endl;

    int i=1;
    while(T.size()<n-1){
        cout<<endl;
        if(!(same_set(grafo[i].ar1,grafo[i].ar2,set))){
            cout<<grafo[i].ar1<<" e "<<grafo[i].ar2<<" nao estao no mesmo set"<<endl;
            uniao(grafo[i].ar1,grafo[i].ar2,set,n);
            for(int j=0;j<n;j++){
                cout<<set[j]<<" ";
            }
            cout<<endl;
            T.push_back(grafo[i]);

        }
        i++;
    }

    return T;
}

void quickSortmai(vetAr *grafo,   int p,  int r){
    if (p<r){
          vetAr temp;
          int x=grafo[r].peso;
          int i=p-1;
        for(  int j=p;j<r;j++){
            if(grafo[j].peso>x){
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

        quickSortmai(grafo,p,q-1);
        quickSortmai(grafo,q+1,r);

    }
}
vector<vetAr> kruskalmaior(vetAr* grafo, int m, int n){
    quickSortmai(grafo,0,m-1);
    vector <vetAr> T;
    T.push_back(grafo[0]);
    int set[n];
    printArestas(grafo,m);
    for(int i = 0;i<n;i++){
        set[i]=i;
    }
    uniao(grafo[0].ar1,grafo[0].ar2,set,n);

    for(int i = 0;i<n;i++){
        cout<<set[i]<<" ";
    }

    cout<<endl;

    int i=1;
    while(T.size()<n-1){
        cout<<endl;
        if(!(same_set(grafo[i].ar1,grafo[i].ar2,set))){
            cout<<grafo[i].ar1<<" e "<<grafo[i].ar2<<" nao estao no mesmo set"<<endl;
            uniao(grafo[i].ar1,grafo[i].ar2,set,n);
            for(int j=0;j<n;j++){
                cout<<set[j]<<" ";
            }
            cout<<endl;
            T.push_back(grafo[i]);

        }
        i++;
    }

    return T;
}

vector<vetAr> primMen(vetAr *grafo, int m, int n){
    int it=0;
    vector <int> z;
    vector <int> v;
    for(int j=0;j<n;j++){
        v.push_back(j);
    }
    z.push_back(it);
    auto apag = find(begin(v),end(v),it);
    v.erase(apag);
    vector <vetAr> T;

    while(z.size()<n){
        int dmin = 99;
        int posicao = 0;
        bool lado = 0;
        for(int i=0;i<m;i++){
            /////Busca///////
            if(binary_search(v.begin(),v.end(),grafo[i].ar1)){
                if(binary_search(z.begin(),z.end(),grafo[i].ar2)){
                    if(dmin >= grafo[i].peso){
                        dmin = grafo[i].peso;
                        posicao = i;
                        lado = 0;
                    }
                }
            }
            if(binary_search(v.begin(),v.end(),grafo[i].ar2)){
                if(binary_search(z.begin(),z.end(),grafo[i].ar1)){
                    if(dmin >= grafo[i].peso){
                        dmin = grafo[i].peso;
                        posicao = i;
                        lado = 1;
                    }
                }
            }
        }

        /////Aresta encontrada////////
        if(lado){
            z.push_back(grafo[posicao].ar2);
            apag=find(begin(v),end(v),grafo[posicao].ar2);
            v.erase(apag);
            T.push_back(grafo[posicao]);

        }
        else{
            z.push_back(grafo[posicao].ar1);
            apag=find(begin(v),end(v),grafo[posicao].ar1);
            v.erase(apag);
            T.push_back(grafo[posicao]);
        }

        for(int i=0;i<z.size();i++){
            cout<<z[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;

    }
    return T;
}

vector<vetAr> primMai(vetAr *grafo, int m, int n){
    int it=0;
    vector <int> z;
    vector <int> v;
    for(int j=0;j<n;j++){
        v.push_back(j);
    }
    z.push_back(it);
    auto apag = find(begin(v),end(v),it);
    v.erase(apag);
    vector <vetAr> T;

    while(z.size()<n){
        int dmax = -1;
        int posicao = 0;
        bool lado = 0;
        for(int i=0;i<m;i++){
            /////Busca///////
            if(binary_search(v.begin(),v.end(),grafo[i].ar1)){
                if(binary_search(z.begin(),z.end(),grafo[i].ar2)){
                    if(dmax <= grafo[i].peso){
                        dmax = grafo[i].peso;
                        posicao = i;
                        lado = 0;
                    }
                }
            }
            if(binary_search(v.begin(),v.end(),grafo[i].ar2)){
                if(binary_search(z.begin(),z.end(),grafo[i].ar1)){
                    if(dmax <= grafo[i].peso){
                        dmax = grafo[i].peso;
                        posicao = i;
                        lado = 1;
                    }
                }
            }
        }

        /////Aresta encontrada////////
        if(lado){
            z.push_back(grafo[posicao].ar2);
            apag=find(begin(v),end(v),grafo[posicao].ar2);
            v.erase(apag);
            T.push_back(grafo[posicao]);

        }
        else{
            z.push_back(grafo[posicao].ar1);
            apag=find(begin(v),end(v),grafo[posicao].ar1);
            v.erase(apag);
            T.push_back(grafo[posicao]);
        }

        for(int i=0;i<z.size();i++){
            cout<<z[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;

    }
    return T;
}

int main()
{

    vetAr grafo[15];

    inserir(grafo[0],0,2,7);inserir(grafo[1],1,2,2);inserir(grafo[2],1,4,8);inserir(grafo[3],1,5,7);inserir(grafo[4],2,5,1);
    inserir(grafo[5],2,3,6);inserir(grafo[6],3,6,6);inserir(grafo[7],4,5,2);inserir(grafo[8],4,7,1);inserir(grafo[9],5,6,5);
    inserir(grafo[10],5,8,1);inserir(grafo[11],6,9,2);inserir(grafo[12],7,8,6);inserir(grafo[13],8,9,5);inserir(grafo[14],5,7,4);

    vector<vetAr> kruskal = primMai(grafo,15,10);

    for(int i=0;i<kruskal.size();i++){
        cout<<kruskal[i].ar1<<"-"<<kruskal[i].ar2<<", P="<<kruskal[i].peso<<endl;
    }

    return 0;
}
