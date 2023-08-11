#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int numCidades, numConfed;
  while (true)
  {

    cin >> numCidades >> numConfed;
    if (numCidades == 0)
      break;

    int numCidades;

    for (int i = 0; i < numConfed; i++)
    {
      cin >> numCidades;

      int cidade;
      for (int j = 0; j < numCidades; j++)
      {
        cin >> cidade;
        cidadesPorConfederacao[cidade].push_back(i);
      }
    }
    for (int i = 0; i < numCidades; i++)
    {

      int u = cidadesPorConfederacao[i][0], v;
      if (cidadesPorConfederacao[i].size() == 1)
        v = u;
      else
        v = cidadesPorConfederacao[i][1];

      // grafo não direcionado
      LA[u].push_back(make_pair(v, i));
      LA[v].push_back(make_pair(u, i));

      grau[u]++;
      grau[v]++;
    }
  }
}