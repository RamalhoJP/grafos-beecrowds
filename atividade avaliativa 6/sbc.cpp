/*
Dupla: Gustavo Biaso Dias Pinto 202210925 e João Pedro Ramalho de Sousa 202210443
Turma 10A
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define BRANCO -1
#define PRETO 1
#define CINZA 2

int max_casamentos = 0;
vector<int> cor;

void dfs(int v, const vector<vector<int>> &lista_adj, vector<bool> &visitado)
{
    cor[v] = CINZA;

    for (int neighbor : lista_adj[v])
    {
        if (cor[v] == BRANCO)
        {
            dfs(neighbor, lista_adj, visitado);
        }
        else if (cor[neighbor] == CINZA && !visitado[neighbor])
        {
            max_casamentos++;
            visitado[neighbor] = true;
        }
    }

    cor[v] = PRETO;
}

int main()
{
    map<string, int> nomes;
    vector<vector<int>> lista_adj;
    int n = 0;
    string pessoa1, pessoa2;

    while (cin >> pessoa1 >> pessoa2)
    {
        if (nomes.find(pessoa1) == nomes.end())
        {
            nomes[pessoa1] = n++;
            lista_adj.push_back(vector<int>());
        }
        if (nomes.find(pessoa2) == nomes.end())
        {
            nomes[pessoa2] = n++;
            lista_adj.push_back(vector<int>());
        }

        lista_adj[nomes[pessoa1]].push_back(nomes[pessoa2]);
    }

    vector<bool> visitado(n, false);
    for (int i = 0; i < n; ++i)
    {
        if (!visitado[i])
        {
            dfs(i, lista_adj, visitado);
        }
    }

    cout << max_casamentos << endl;
    return 0;
}