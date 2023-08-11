#include<iostream>

using namespace std;

int main()
{
    int n, m, p; // numero de vertices; numero de arestas do grafo
 
    cin >> n >> m >> p;

      int** M = new int*[n+1]; // matriz de adjacencia
      int** W = new int*[n+1]; // matriz do fecho transitivo
      for(int i = 1; i <= n; i++)
      {
          M[i] = new int[n+1];
          W[i] = new int[n+1];
      }
  
      for(int u = 1; u <= n; u++)
          for(int v = 1; v <= n; v++)
              M[u][v] = W[u][v] = 0;
     
      // leitura do grafo
      int u, v;
      for(int i = 0; i < m; i++)
      {
        cin >> u >> v; // lendo as arestas do grafo
        M[u][v] = M[v][u] = W[u][v] = W[v][u] = 1;
      }
  
      // Implementacao do algoritmo de Warshall
      for(int k = 1; k <= n; k++)
          for(int u = 1; u <= n; u++)
              for(v = 1; v <= n; v++)
                  W[u][v] = W[u][v] || (W[u][k] && W[k][v]);

      int a, b;

      for(int i = 1; i <= p; i++){ 
        cin >> a >> b;
        if(W[a][b]){
          cout<<"Lets que lets"<<endl;
        } else {
          cout<<"Deu ruim"<<endl;
        }
      }

     for(int u = 0; u <= n; u++)
     {
        delete M[u];
        delete W[u];
     }
     delete[] M;
     delete[] W;
     
    return 0;
}