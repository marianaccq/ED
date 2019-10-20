#include <iostream>
#define vert int
using namespace std;

//Inicia a struct grafo
typedef struct s {
   int v;
   int a;
   int **adj;
} Grafo;


//Aloca a matriz de adjacencias
static int **iniciaMatriz( int r, int c, int val) {
   int **m = new int *[r];
   for (vert i = 0; i < r; i++)
      m[i] = new int [c];
   for (vert i = 0; i < r; i++)
      for (vert j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}

//Inicia um grafo com numero de vertices V
Grafo* iniciaGrafo(int v) {
   Grafo *G = new Grafo();
   G->v = v;
   G->a = 0;
   G->adj = iniciaMatriz( v, v, 0);
   return G;
}

void insereConexao(Grafo *G, vert v, vert w) {
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1;
      G->adj[w][v] = 1;
      G->a++;
   }
}
void removeConexao(Grafo *G, vert v, vert w) {
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0;
      G->adj[w][v] = 0;
      G->a--;
   }
}
void printGrafo(Grafo *G) {
   for (vert v = 0; v < G->v; ++v) {
      cout<<"Vertice "<<v<<": Se conecta com: ";
      for (vert w = 0; w < G->v; ++w)
         if (G->adj[v][w] == 1)
            cout<<w;
      cout<<endl;
   }
}
int main(){
    Grafo *G = iniciaGrafo(10);
    insereConexao(G, 3, 5);
    printGrafo(G);
}
