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

void inserir2(int x, int y ,No **lista){
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

typedef struct Pilha
{
  TipoNo *topo;
  int tamanho;
} TipoPilha;

void IniciaPilha(TipoPilha *pilha)
{
  pilha->topo = NULL;
  pilha->tamanho = 0;
}

int pilhaVazia(TipoPilha *pilha)
{
  return (pilha->topo == NULL);
}

void Empilha(int x, TipoPilha *pilha)
{
  TipoNo *aux;

  aux = (TipoNo *) malloc(sizeof(TipoNo));
  aux->chave = x;
  aux->next = pilha->topo;
  pilha->topo = aux;
  pilha->tamanho++;
}

int Desempilha(TipoPilha *pilha)
{
  TipoNo *q;  int v;

  if (pilhaVazia(pilha))
  {
    printf("Erro: Lista vazia\n");
    return 0;
  }
  q = pilha->topo;
  pilha->topo = q->next;
  v = q->chave;
  free(q);
  pilha->tamanho--;
  return v;
}

No **criaGrafo(int **lab, int n){
    No **grafo = new No*[n*n];
    for(int i=0;i<n*n;i++){
        grafo[i] = new No();
        grafo[i]->chave = i;
        grafo[i]->next = grafo[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(lab[i][j]==0){
                if(lab[i+1][j]==0){
                    int x1=(n)*i;
                    int x2=(n)*(i+1);
                    inserir2(x1+j,x2+j,grafo);
                }

                if(lab[i][j+1]==0){
                    int x = (n)*i;
                    inserir2(x+j,x+j+1,grafo);
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        if(lab[i][n-1] == 0){
            if(lab[i+1][n-1]==0){
                int x1=(n)*i;
                int x2=(n)*(i+1);
                inserir2(x1+n-1,x2+n-1,grafo);
            }
        }
        if(lab[n-1][i]==0){
            if(lab[n-1][i+1]==0){
                int x = (n)*(n-1);
                inserir2(x+i,x+i+1,grafo);
            }
        }
    }




    return grafo;
}

void BP(No **lista, bool *flag, int vert, int dest, Pilha *p, bool &encontrou){
    flag[vert] = 1;
    No *aux = lista[vert]->next;
    Empilha(vert,p);
    if(vert == dest){
        encontrou=0;
    }
    while(aux!=lista[vert]&&encontrou){
        int w = aux->chave;
        if(!flag[w]){
            aux->visita=1;
            flag[w]=1;

            BP(lista,flag,w,dest,p,encontrou);
            if(encontrou){
                int lixo = Desempilha(p);
            }
        }
        aux=aux->next;
    }
}

int *caminho(Pilha *p, int &tam){
    tam = p->tamanho;
    int *cam = new int[tam];
    for(int i=tam-1;i>=0;i--){
        cam[i] = Desempilha(p);
    }
    return cam;
}

int main()
{
    int n=6;

    int **lab = new int*[n];

    for(int i=0;i<n;i++){
        lab[i] = new int[n];
    }

    lab[0][0]=0;lab[0][1]=-1;lab[0][2]=0;lab[0][3]=0;lab[0][4]=0;lab[0][5]=-1;
    lab[1][0]=0;lab[1][1]=0;lab[1][2]=-1;lab[1][3]=0;lab[1][4]=-1;lab[1][5]=0;
    lab[2][0]=0;lab[2][1]=0;lab[2][2]=0;lab[2][3]=0;lab[2][4]=0;lab[2][5]=-1;
    lab[3][0]=0;lab[3][1]=-1;lab[3][2]=-1;lab[3][3]=0;lab[3][4]=0;lab[3][5]=0;
    lab[4][0]=-1;lab[4][1]=0;lab[4][2]=0;lab[4][3]=0;lab[4][4]=-1;lab[4][5]=-1;
    lab[5][0]=0;lab[5][1]=0;lab[5][2]=-1;lab[5][3]=0;lab[5][4]=0;lab[5][5]=0;

    No **grafo = criaGrafo(lab,n);

    Pilha *p = new Pilha;
    IniciaPilha(p);

    bool flag[n*n];
    bool encontrou = 1;
    for(int i=0;i<n*n;i++){
        flag[i] = 0;
    }

    int destino  = n*n - 1;
    BP(grafo,flag,0,destino,p,encontrou);

    int tam;
    int *cam = caminho(p,tam);

    for(int i=0;i<tam;i++){
        cout<<cam[i]/n<<" "<<cam[i]%n<<endl;
    }

    return 0;
}
