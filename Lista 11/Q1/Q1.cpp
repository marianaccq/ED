#include <iostream>
#define vert int
using namespace std;

typedef struct s{
	int chave;
	struct s *right;
	struct s *left;
	struct s *pai;
} No;

No* getMin(No *raiz, No *&mini){

	if (raiz->left !=NULL)
        getMin(raiz->left, mini);
    if (raiz->left ==NULL && raiz->right ==NULL){
        if(raiz->chave < mini->chave){
            mini = raiz;
        }
    }
	if (raiz->right !=NULL)
        getMin(raiz->right, mini);

}

void pruffer(No *n1){
    int cont = 0;
    int p[3];
    while(cont != 3){
        No *mini = new No();
        mini->chave = 100000;
        getMin(n1, mini);
        p[cont] = mini->pai->chave;
        if(mini->pai->left == mini)
            mini->pai->left = NULL;
        if(mini->pai->right == mini)
            mini->pai->right = NULL;
        cont++;
    }
    cout<<"O codigo de Pruffer da arvore e: "<<endl;
    for(int i = 0; i<3; i++){
        cout<<p[i]<<" ";
    }
}
int main(){
    /*
             5
           /   \
          1     4
        /  \
       2    3
       */

    No *n1 = new No();
    No *n2 = new No();
    No *n3 = new No();
    No *n4 = new No();
    No *n5 = new No();
    n1->chave = 5;
    n2->chave = 1;
    n3->chave = 4;
    n4->chave = 2;
    n5->chave = 3;
    n1->left = n2;
    n2->pai = n1;
    n1->right = n3;
    n3->pai = n1;
    n2->left = n4;
    n4->pai = n2;
    n2->right = n5;
    n5->pai = n2;
    pruffer(n1);
}
