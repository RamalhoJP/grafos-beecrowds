#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> confederacao[500];
vector<pair<int, int>> L[100];
int ncomponentes = 0;
int low[100], h[100];
vector<bool> visitado, ponte;

void dfs(int atual, int p, int atualh)
{
  if (visitado[atual])
    return;

  visitado[atual] = true;
  h[atual] = low[atual] = atualh;
  bool back = true;

  int to;

  for (int i = L[atual].size() - 1; i >= 0; --i)
  {
    to = L[atual][i].first;

    if (to == p)
    {
      if (!back)
        low[atual] = min(low[atual], atualh - 1);
      back = false;
    }
    else if (visitado[to])
    {
      low[atual] = min(low[atual], h[to]);
    }
    else
    {
      dfs(to, atual, atualh + 1);
      low[atual] = min(low[atual], low[to]);

      if (low[to] > atualh)
        ponte[L[atual][i].second] = true;
    }
  }
}

int main()
{

  int N, C;
  vector<int> grau;

  while (true)
  {

    cin >> N >> C;

    if (N == 0)
    {
      break;
    }

    for (int i = 0; i < N; i++)
      confederacao[i].clear();

    int K;

    for (int i = 0, K; i < C; i++)
    {
      cin >> K;
      int c;
      for (int j = 0; j < K; ++j)
      {
        cin >> c;
        confederacao[c].push_back(i);
      }
    }

    grau.assign(N, 0);

    for (int i = 0; i < N; i++)
    {
      int u = confederacao[i][0], v;

      if (confederacao[i].size() == 1)
        v = u;
      else
        v = confederacao[i][1];

      grau[u]++;
      grau[v]++;
      L[u].push_back(make_pair(v, i));
      L[v].push_back(make_pair(u, i));
    }

    cout << resposta;
  }
}

return 0;
}