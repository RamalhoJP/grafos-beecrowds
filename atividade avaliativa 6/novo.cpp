#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> confederacao;
vector<vector<pair<int, int>>> LA;
vector<int> grau, low, altura;
vector<bool> visitado, ponte;

int N, C, numComponentesConexas;

void dfs(int atual, int pai, int alturaAtual)
{
  if (visitado[atual])
    return;

  visitado[atual] = true;
  altura[atual] = low[atual] = alturaAtual;

  bool retorno = true;
  int vizinho;

  for (int i = LA[atual].size() - 1; i >= 0; i--)
  {
    vizinho = LA[atual][i].first;

    if (vizinho == pai)
    {
      if (!retorno)
        low[atual] = min(low[atual], alturaAtual - 1);
      retorno = false;
    }
    else if (visitado[vizinho])
    {
      low[atual] = min(low[atual], altura[vizinho]);
    }
    else
    {
      dfs(vizinho, atual, alturaAtual + 1);
      low[atual] = min(low[atual], low[vizinho]);

      if (low[vizinho] > alturaAtual)
        ponte[LA[atual][i].second] = true;
    }
  }
}

int operacoes()
{
  vector<int> grausImpares;

  for (int i = 0; i < C; ++i)
  {
    if (grau[i] & 1)
    {
      grausImpares.push_back(i);
    }
  }

  visitado.assign(C, false);
  ponte.assign(N, false);

  numComponentesConexas = 0;

  for (int i = 0; i < C && numComponentesConexas <= 1; i++)
  {
    if (!visitado[i] && grau[i] != 0)
    {
      dfs(i, -1, 0);
      numComponentesConexas++;
    }
  }

  if (numComponentesConexas > 1 || grausImpares.size() > 2)
    return -1;
  else if (grausImpares.size() == 0)
    return 0;
  else
  {
    int resposta = N;

    for (int i = 0; i <= 1; i++)
    {
      int atual = grausImpares[i];

      if (LA[atual].size() == 1)
        resposta = min(resposta, LA[atual][0].second);
      else
      {
        for (int j = LA[atual].size() - 1; j >= 0; j--)
        {
          if (!ponte[LA[atual][j].second])
            resposta = min(resposta, LA[atual][j].second);
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
    cin >> N >> C;

    if (N == 0)
      break;

    confederacao.assign(N, vector<int>());
    grau.assign(C, 0);
    LA.assign(C, vector<pair<int, int>>());
    low.assign(C, 0);
    altura.assign(C, 0);

    int K, c;

    for (int i = 0; i < C; i++)
    {
      cin >> K;

      for (int j = 0; j < K; j++)
      {
        cin >> c;
        confederacao[c].push_back(i);
      }
    }

    for (int i = 0; i < N; i++)
    {

      int u = confederacao[i][0], v;
      if (confederacao[i].size() != 1)
        v = confederacao[i][1];
      else
        v = u;

      LA[u].push_back(make_pair(v, i));
      LA[v].push_back(make_pair(u, i));

      grau[u]++;
      grau[v]++;
    }

    int resposta = operacoes();

    cout << resposta << endl;
  }
  return 0;
}