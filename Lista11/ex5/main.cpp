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

void printDireto(No *cabeca){
    cout<<cabeca->chave<<" :";
    No *aux = cabeca->next;
    while (aux!=cabeca){
        cout<<aux->chave<<"->";
        aux = aux->next;
    }
    cout<<endl;
}

typedef struct Fila
{
  TipoNo *inicio, *fim;
  int tamanho;
} TipoFila;

void IniciaFila(TipoFila *fila)
{
  fila->inicio = NULL;
  fila->fim = NULL;
  fila->tamanho=0;
}

int filaVazia(TipoFila *fila)
{
  return (fila->inicio == NULL);
}

void Enfileira(int raiz, TipoFila *fila)
{
  TipoNo *aux;
  aux = (TipoNo *) malloc(sizeof(TipoNo));
  aux->chave=raiz;
  aux->next=NULL;
  if (filaVazia(fila)){
    fila->inicio=aux;
    fila->fim=aux;
  }
  else {
  fila->fim->next = aux;
  fila->fim = aux;
  }
  fila->tamanho++;
}

int Desenfileira(TipoFila *fila)
{
  TipoNo *q; int v;
  if (filaVazia(fila))
  {
    printf("Fila esta vazia\n");
    return -1;
  }
  q = fila->inicio;
  v = fila->inicio->chave;
  fila->inicio = fila->inicio->next;
  free(q);
  fila->tamanho--;
  return v;
}

void BL(No **lista , int inicio, bool *flag, int *dist){
    Fila *F = new Fila();
    IniciaFila(F);
    dist[inicio] = 0;
    flag[inicio] = 1;
    Enfileira(inicio,F);
    while(!filaVazia(F)){
        int v = Desenfileira(F);
        No *vert = lista[v]->next;
        while(vert!=lista[v]){
            int w=vert->chave;
            if(!flag[w]){
                dist[w]=dist[v]+1;
                Enfileira(w,F);
                flag[w]=1;
                vert->visita=1;
            }
            vert=vert->next;
        }
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
    inserir(lista[3],2);inserir(lista[4],0);inserir(lista[5],1);

    bool flag[10];
    for(int i=0;i<10;i++){
        flag[i]=0;
    }

    int origem = 3;

    int dist[6];
    for(int i=0;i<6;i++){
        dist[i]=-1;
    }

    BL(lista,origem,flag,dist);

    for(int i=0;i<6;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;

    return 0;
}
