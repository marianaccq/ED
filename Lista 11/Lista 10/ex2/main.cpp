#include <iostream>

using namespace std;

typedef struct s{
    int chave; // chave (conteúdo armazenado)
    struct s *next; // ponteiro para o próximo elemento
} No;

void busca(No *cabeca, No **ant, No **pont, int x){
    *ant = cabeca; // ant agora aponta pra cabeça e isso se reflete fora da funçao
    *pont = NULL;
    No *aux = cabeca->next;
    while (aux!=cabeca){
        if (aux->chave < x){
            *ant = aux; // ant agora aponta pra aux e isso se reflete fora da funçao
            aux = aux->next;
        } else{
            if(aux->chave==x){
                *pont = aux;
            }
            aux = cabeca;
        }
    }
}

void inserir(No *cabeca, int novoVaor){
    No *ant=NULL, *pont=NULL;
    busca(cabeca, &ant, &pont, novoVaor); // ATENCAO:  &ant, &pont
    if (pont==NULL){
        No *novoNo = new No();
        if (novoNo!=NULL){
            novoNo->chave = novoVaor;
            novoNo->next = ant->next;
            ant->next = novoNo;
        }
    } else {
        cout<<"Elemento "<<novoVaor<<" já se encontra na lista"<<endl;
    }
}

void printDireto(No *cabeca){
    No *aux = cabeca->next;
    while (aux!=cabeca){
        cout<<aux->chave<<" ";
        aux = aux->next;
    }
    cout<<endl;
}

void remover(No *cabeca, int valor){
    No *ant=NULL, *pont=NULL;
    busca(cabeca, &ant, &pont, valor); // ATENCAO:  &ant, &pont
    if (pont!=NULL){ // o elemento deve estar na lista
        ant->next = pont->next;
        delete pont; // IMPORTANTE NAO ESQUECER
    } else {
        cout<<"Elemento "<<valor<<" não se encontra na lista"<<endl;
    }
}

void retorno(int *pruf, int n , No **lista){
    int grau[n+2];
    for(int i=0;i<n+2;i++){
        int cont=1;
        for(int j=0;j<n;j++){
            if(pruf[j]==i){
                cont++;
            }
        }
        grau[i]=cont;
        cout<<grau[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<(n+2);i++){
        lista[i] = new No();
        lista[i]->chave = i;
        lista[i]->next=lista[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n+2;j++){
            if(grau[j]==1){
                cout<<"inserindo "<<pruf[i]<<" e "<<j<<endl;
                inserir(lista[j],pruf[i]);
                inserir(lista[pruf[i]],j);
                grau[j]--;
                grau[pruf[i]]--;
                cout<<"inseriu"<<endl;

                for(int k=0;k<n+2;k++){
                    cout<<grau[k]<<" ";
                }
                cout<<endl;
                for(int k=0;k<n+2;k++){
                    printDireto(lista[k]);
                }
                cout<<endl;
                j=n+2;
            }
        }
    }
}

int main()
{
    int n;
    cout<<"Tamanho pruffer"<<endl;
    cin>>n;

    int pruf[n];
    cout<<"Inserir pruffer"<<endl;
    for(int i=0;i<n;i++){
        cin>>pruf[i];
    }

    No **lista = new No*();
    retorno(pruf,n,lista);

    for(int i=0;i<n;i++){
        printDireto(lista[i]);
    }


    return 0;
}
