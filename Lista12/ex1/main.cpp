#include <iostream>

using namespace std;

int buscaMenor(int *d, int n, bool *A){
    int trono = 0;
    int menor = 9999;
    for(int i=0;i<n;i++){
        if(d[i]<menor && A[i]){
            menor = d[i];
            trono = i;
        }
    }
    return trono;
}

void dijkstra(int **grafo, int n, int *d, int *rot){
    d[0]=0; rot[0]=9999;
    bool F[n],A[n];
    for(int i=0;i<n;i++){
        F[i]=0;
        A[i]=1;
    }
    F[0]=1;
    A[0]=0;

    for(int i=1;i<n;i++){
        if(grafo[0][i]!=0){
            d[i]=grafo[0][i]; rot[i]=0;
        }
        else{
            d[i]=9999; rot[i]=-1;
        }
    }

    bool aVazio = false;

    while(!aVazio){
        int i=buscaMenor(d,n,A);
        A[i]=0;F[i]=1;
        for(int j=0;j<n;j++){
            if(grafo[i][j]!=0 && A[j]){
                cout<<i<<"-"<<j<<": "<<grafo[i][j]<<" "<<A[j]<<endl;
                if(d[j]>(d[i]+grafo[i][j])){
                    d[j] = d[i]+grafo[i][j]; rot[j] = i;
                }
            }
        }
        aVazio = true;

        for(int j=0;j<n;j++){
            if(A[j]){
                aVazio = false;
            }
        }
    }
}

int main()
{

    int n=7;
    int **grafo = new int* [n];
    for(int i=0;i<n;i++){
        grafo[i] = new int[n];
    }

    cout<<"Inserir grafo"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grafo[i][j];
        }
    }

    int d[n]; int rot[n];

    dijkstra(grafo,n,d,rot);

    for(int i=0;i<n;i++){
        cout<<rot[i]<<" "<<d[i]<<endl;
    }

    return 0;
}
