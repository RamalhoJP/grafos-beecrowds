#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int divide(int u, vector<int>* lista_adj, bool& bem){
    int tam, pesoTemp = 0, pesoTemp2 = 0,pesoaux=1;

    tam = lista_adj[u].size();
   
        for (int i = 0; i < tam; i++){
            if(pesoTemp != 0){
                pesoTemp2 = divide(lista_adj[u].at(i), lista_adj, bem);
                if(pesoTemp != pesoTemp2){
                    bem = false;
                }
               
            } else {
                pesoTemp = divide(lista_adj[u].at(i), lista_adj, bem);
            }
        }
        pesoTemp = pesoTemp2 + pesoTemp;
        pesoaux = pesoaux + pesoTemp;

    return pesoaux;
}

int main()
{
    int n, s = 0;
    bool bem;
    cin >> n;

    // iniciando as estruturas auxiliares
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
 
    divide(s, lista_adj, bem);


    if(bem){
        cout<<"bem";
    } else {
        cout<<"mal";
    }

    return 0;
}
