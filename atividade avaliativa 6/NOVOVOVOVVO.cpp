#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> cidadesPorConfederacao;
vector<vector<pair<int, int>>> listaAdj;

vector<int> grau, menorAltura, altura;
vector<bool> visitado, ehPonte;

int numCidades, numConfederacoes, numComponentesConexos;

void dfs(int atual, int pai, int alturaAtual)
{
  if (visitado[atual])
    return;

  visitado[atual] = true;

  altura[atual] = menorAltura[atual] = alturaAtual;

  bool EmRetorno = true;
  int vizinho;

  for (int i = listaAdj[atual].size() - 1; i >= 0; i--)
  {
    vizinho = listaAdj[atual][i].first;

    if (vizinho == pai)
    {
      if (!EmRetorno)
      {
        menorAltura[atual] = min(menorAltura[atual], alturaAtual - 1);
      }
      EmRetorno = false;
    }
    else if (visitado[vizinho])
    {
      menorAltura[atual] = min(menorAltura[atual], altura[vizinho]);
    }
    else
    {
      dfs(vizinho, atual, alturaAtual + 1);
      menorAltura[atual] = min(menorAltura[atual], menorAltura[vizinho]);

      if (menorAltura[vizinho] > alturaAtual)
        ehPonte[listaAdj[atual][i].second] = true;
    }
  }
}

vector<int> encontrarGrausImpares()
{
  vector<int> grausImpares;
  for (int i = 0; i < numConfederacoes; i++)
  {
    if (grau[i] & 1)
    {
      grausImpares.push_back(i);
    }
  }
  return grausImpares;
}

int solucao()
{
  vector<int> grausImpares = encontrarGrausImpares();
  numComponentesConexos = 0;

  for (int i = 0; i < numConfederacoes; i++)
  {
    if (!visitado[i] && grau[i] > 0)
    {
      numComponentesConexos++;
      dfs(i, -1, 0);
    }
  }

  if (numComponentesConexos > 1 || grausImpares.size() > 2)
    return -1;
  else if (grausImpares.size() == 0)
    return 0;
  else
  {
    int resposta = numCidades;

    for (int i = 0; i <= 1; i++)
    {
      int atual = grausImpares[i];

      if (listaAdj[atual].size() == 1)
        resposta = min(resposta, listaAdj[atual][0].second);
      else
      {
        for (int j = listaAdj[atual].size() - 1; j >= 0; j--)
        {
          if (!ehPonte[listaAdj[atual][j].second])
            resposta = min(resposta, listaAdj[atual][j].second);
        }
      }
    }

    return resposta;
  }
}

int main()
{

  while (true)
  {
    cin >> numCidades >> numConfederacoes;

    if (numCidades == 0)
      break;

    cidadesPorConfederacao.assign(numCidades, vector<int>());
    grau.assign(numConfederacoes, 0);
    listaAdj.assign(numConfederacoes, vector<pair<int, int>>());
    menorAltura.assign(numConfederacoes, 0);
    altura.assign(numConfederacoes, 0);
    visitado.assign(numConfederacoes, false);
    ehPonte.assign(numConfederacoes, false);

    int numCidadesConfederacao;

    for (int i = 0; i < numConfederacoes; i++)
    {
      cin >> numCidadesConfederacao;

      int cidade;
      for (int j = 0; j < numCidadesConfederacao; j++)
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

      listaAdj[u].push_back(make_pair(v, i));
      listaAdj[v].push_back(make_pair(u, i));

      grau[u]++;
      grau[v]++;
    }

    int resposta = solucao();

    cout << resposta << endl;
  }

  return 0;
}
/*
4 4
1 3
3 0 1 3
2 0 2
1 2
3 4
1 0
3 0 1 2
1 1
1 2
3 4
1 1
2 1 0
2 0 2
1 2
0 0
*/