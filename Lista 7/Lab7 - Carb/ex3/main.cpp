#include <iostream>

using namespace std;

struct nodo{
    int chave;
    int conteudo;
    struct nodo *left;
    struct nodo *right;
    struct nodo *pai;
};
typedef struct nodo No;

typedef struct Noh
{
  No *valor;
  struct Noh *prox;
} TipoNo;

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

bool pilhaVazia(TipoPilha *pilha)
{
  return (pilha->topo == NULL);
}

void Empilha(No *x, TipoPilha *pilha)
{
  TipoNo *aux;

  aux = (TipoNo *) malloc(sizeof(TipoNo));
  aux->valor = x;
  aux->prox = pilha->topo;
  pilha->topo = aux;
  pilha->tamanho++;
}

No *Desempilha(TipoPilha *pilha)
{
  TipoNo *q;  No *v;

  if (pilhaVazia(pilha))
  {
    printf("Erro: Lista vazia\n");
    return 0;
  }
  q = pilha->topo;
  pilha->topo = q->prox;
  v = q->valor;
  free(q);
  pilha->tamanho--;
  return v;
}

void buscaABB_recursiva(No *raiz, No **pt_retorno, int x, int &f){
    if (raiz!=NULL){
        if (raiz->chave == x){
            *pt_retorno = raiz; // pt_retorno agora aponta apra o elemento encontrado
            f = 1;
        } else {
            if (x < raiz->chave ){
                if (raiz->left == NULL) f=2; // volta na recursao.
                else {
                    *pt_retorno = raiz->left; // essa linha é importante porque a busca,
                    // caso nao encontre o nó desejado, precisa retornar o elemento que seria pai do elemento procurado.
                    buscaABB_recursiva(raiz->left,pt_retorno, x, f); // Chama recursivamente para a esquerda
                }
            } else{
                if (raiz->right == NULL) f=3; // volta na recursao.
                else {
                    *pt_retorno = raiz->right; // idem
                    buscaABB_recursiva(raiz->right,pt_retorno, x, f);// chama recursivamente para a direita
                }
            }
        }
    }

}

/* PROCEDIMENTO DE INSERCAO NUMA ARVORE BINARIA DE BSUCA SIMPLES
    @param raiz da arvore. Deve ser um ponteiro para ponteiro, pois, em caso de a arvore ser vazia, o parametro raiz deve apontar para a nova raiz da arvore
   O parametro raiz deve ser NULL, inicialmente, caaso a arvore seja vazia
   @param x inteiro no a ser inserido
*/
void insert(int x, No **raiz){
    int f=0;
    No *pt_retorno = *raiz;
    buscaABB_recursiva(*raiz, &pt_retorno, x, f); // NOTEM NOTEM NOTEM NOTEM NOTEM NOTEM NOTEM o &pt_retorno e o *raiz
    if (f==1) cout<<"Elemento "<< x <<" ja existe"<<endl;
    else {
        No *novo_no = new No(); // cria novo nó
        novo_no->chave = x; // atribui a chave
        novo_no->left = NULL; // novo nó inicialmente é folha
        novo_no->right = NULL;
        novo_no->pai = NULL;
        if (f==0) *raiz = novo_no; // o unico caso em que o ponteiro da raiz é modificado
        else {
            if (f==2){
                pt_retorno->left = novo_no; // o novo nó eh filho esquerdo
                novo_no->pai = pt_retorno;
            }
            else {
                pt_retorno->right = novo_no; // idem
                novo_no->pai = pt_retorno;
            }
        }
    }
}

void in_ordem_aux(No *raiz){

    if (raiz->left !=NULL) in_ordem_aux(raiz->left);
    cout<<raiz->chave<<" ";
    if (raiz->right !=NULL) in_ordem_aux(raiz->right);

}
void in_ordem(No *raiz){
    if (raiz!=NULL) in_ordem_aux(raiz);
}

void cresc(No *raiz){
    Pilha *P = new TipoPilha();
    bool fim = false;
    do{
        while(raiz!=NULL){
            Empilha(raiz,P);
            raiz=raiz->left;
        }
        if(!pilhaVazia(P)){
            raiz = Desempilha(P);
            cout<<raiz->chave<<" ";
            raiz=raiz->right;
        }
        else{
            fim=true;
        }
    }while(!fim);
}

void decresc(No *raiz){
    Pilha *P = new TipoPilha();
    bool fim = false;
    do{
        while(raiz!=NULL){
            Empilha(raiz,P);
            raiz=raiz->right;
        }
        if(!pilhaVazia(P)){
            raiz = Desempilha(P);
            cout<<raiz->chave<<" ";
            raiz=raiz->left;
        }
        else{
            fim=true;
        }
    }while(!fim);
}
// algoritmo recursivo em pos-ordem
int getAltura(No *raiz){
    if (raiz!=NULL){
            int left = getAltura(raiz->left);  // chamada recursiva para a esqueda
            int right = getAltura(raiz->right); // chamada recursiva para a direita
            if (left>right) return left + 1; // soma +1 na altura (sobe o nível)
            else return right +1;
    }
    return 0;
}




int main(){
    No *arv = new No();
    arv=NULL;
    int x=-1;
    int f=0;
    cout<<"Inserir valores na arvore"<<endl;
    while(1){
        cin>>x;
        if(x==0){
            break;
        }
        insert(x,&arv);
    }
    decresc(arv);
    cout<<endl;


    return 0;
}

