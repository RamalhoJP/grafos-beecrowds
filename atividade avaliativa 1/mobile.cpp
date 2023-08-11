#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int percorre(int u, vector<int>* lista_adj, bool& certo){
	int n,peso,peso_atual,peso_total;
	
	n = lista_adj[u].size();
	peso_total = 1;
	
	for(int i=0; i<n; i++){
		peso_atual = percorre(lista_adj[u][i],lista_adj,certo);
		if(i == 0){
			peso = peso_atual;
		}else if(peso != peso_atual){
			certo = false;
		}
		peso_total += peso_atual;
	}
	return peso_total;
}

int main()
{  
  int n;
  cin >> n;
    // iniciando as estruturas auxiliares  
    vector<int>* lista_adj = new vector<int>[n+1];
    
    // leitura do grafo
    int u, v;
    for(int i = 0; i < n; i++)
    {
      cin >> u >> v; // lendo as arestas do grafo
      // evitando a leitura de vertices repetidos nas listas
      // grafo nao-orientado
      lista_adj[v].push_back(u); //v -> u
    }

    int s = 0; // vertice origem
    bool certo = true;
    percorre(s,lista_adj,certo);
    
    if(certo){
		cout<<"bem";
	}else{
		cout<<"mal";
	}
	
	return 0;
}
