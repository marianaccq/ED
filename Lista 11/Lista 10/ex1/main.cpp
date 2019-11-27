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

void pruffer(No **lista, int n, int *resp){
    bool flag = true;
    int k=0;
    while(flag){
        flag = false;
        for(int i=0;i<n;i++){
            if (lista[i]->next != lista[i]){
                if(lista[i]->next->next== lista[i]){
                    int remov = lista[i]->next->chave;
                    resp[k]=remov;
                    k++;
                    flag = true;
                    remover(lista[i],remov);
                    remover(lista[remov-1],i+1);
                    i=n;
                }
            }
        }
        if(k==n-2){
            return;
        }
    }

}

int main()
{
    int n;
    cout<<"n"<<endl;
    cin>>n;

    No **lista = new No*();

    for(int i=0;i<n;i++){
        lista[i] = new No();
        lista[i]->chave = i;
        lista[i]->next = lista[i];
    }
    int ent1, ent2;
    while(1){
        cout<<"Vertice 1"<<endl;
        cin>>ent1;
        if(ent1 == 0){
            break;
        }
        cout<<"Vertice 2"<<endl;
        cin>>ent2;
        inserir(lista[ent1-1],ent2);
        inserir(lista[ent2-1],ent1);
        cout<<endl;
    }
    int resp[n-2];

    pruffer(lista,n,resp);

    for(int i=0;i<n-2;i++){
        cout<<resp[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(lista[i]->next!=lista[i]){
            printDireto(lista[i]);
        }
    }
    cout<<endl;

    return 0;
}
