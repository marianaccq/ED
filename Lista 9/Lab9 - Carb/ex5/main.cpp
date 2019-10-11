#include <iostream>

using namespace std;

void troca(int &x, int &y){
    int aux=x;
    x=y;
    y=aux;
}

void printH(int H[], int n){
    for(int i=0;i<n;i++){
        cout<<H[i]<<" ";
    }
    cout<<endl;
}

void descer(int D[],int V[], int P[],int i, int n){
    int j= 2*i+1; // filho esquerdo
    if(j<=n){
        if(j<n){
            if(D[j]>D[j-1]){
                j++;
            }
        }
        if(D[i]<D[j-1]){
            troca(D[i],D[j-1]);
            troca(V[i],V[j-1]);
            troca(P[i],P[j-1]);
            descer(D,V,P,j-1,n);
        }
    }
}

void arranjar(int D[],int V[],int P[],int n){
    for(int i=(n+1)/2;i>=0;i--){
        descer(D,V,P,i,n);
    }
}

int roubo(int V[], int P[], int m, int n){
    int D[n];
    for(int i=0;i<n;i++){
        D[i]=V[i]/P[i];
    }
    int total=0;
    int valor=0;
    while(total<m){
        arranjar(D,V,P,n);
        printH(D,n);
        printH(V,n);
        printH(P,n);
        cout<<endl;
        valor+=V[0];
        total+=P[0];
        D[0]=0;
    }

    if(total>m){
        int dif=total-m;
        valor-= (dif*V[0]/P[0]);

    }
    return valor;


}


int main()
{
    int n;
    cout<<"Numero de barras"<<endl;
    cin>>n;

    cout<<"Valor das barras"<<endl;
    int V[n];

    for(int i=0;i<n;i++){
        cin>>V[i];
    }

    cout<<"Peso das barras"<<endl;
    int P[n];

    for(int i=0;i<n;i++){
        cin>>P[i];
    }

    int m;
    cout<<"capacidade da mala"<<endl;
    cin>>m;

    cout<<endl;

    int valor = roubo(V,P,m,n);

    cout<<"valor roubado = "<<valor<<endl;
    return 0;
}
