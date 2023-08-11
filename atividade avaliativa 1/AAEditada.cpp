#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int divide(int u, vector<int>* lista_adj, int* peso, bool& bem){
    int tam, pesoTemp = 0, pesoTemp2 = 0;

    tam = lista_adj[u].size();
    for (int i = 0; i < tam; i++){
		pesoTemp = divide(lista_adj[u].at(i), lista_adj, peso, bem);
        if(i == 0){
			pesoTemp2 = pesoTemp;
        }else if(pesoTemp != pesoTemp2){
             bem = false;
        }
        peso[u] = peso[u] + pesoTemp;
    }
    return peso[u];
}

int main()
{
    int n, s = 0;
    bool bem;
    cin >> n;

    // alocando as estruturas auxiliares
    int *peso = new int[n + 1]; // peso de todos os vertices em relacao a origem s

    // iniciando as estruturas auxiliares
    for (int i = 0; i <= n; i++)
    {
        peso[i] = 1;
    }

    vector<int> *lista_adj = new vector<int>[n + 1];

    // leitura do grafo
    int u, v;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v; // lendo as arestas do grafo

        // evitando a leitura de vertices repetidos nas listas
        if (find(lista_adj[u].begin(), lista_adj[u].end(), v) != lista_adj[u].end())
        {
            continue;
        }

        // grafo nao-orientado
        lista_adj[v].push_back(u); // v -> u
    }
	bem = true;
    // AQUI QUE FICAVA O WHILE
    divide(s, lista_adj, peso, bem);

    delete[] peso;

    if(bem){
        cout<<"bem";
    } else {
        cout<<"mal";
    }

    return 0;
}
