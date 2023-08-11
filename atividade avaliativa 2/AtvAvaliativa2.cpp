#ifndef DEFINICOES_H
#define DEFINICOES_H

#include<utility>
#include<vector>
using namespace std;

typedef pair<int, int> ii; // pares de inteiros
typedef vector<int> vi; // vetor de inteiros
typedef vector<ii> vii; // vetor de pares de inteiros

#endif

#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

// armazena a informacao se o vertice foi explorado ou nao
vi explorado;

// heap que armazena o vertices e suas prioridades a cada iteracao
priority_queue<ii> Q;

// lista de adjacencia
vector<vii> LA;

// numero de vertices
int n;

// numero de arestas
int m;

// vertice inicial
int a = 1;

// vertice final
int b = 1;

// lista de valores de W
vector<int> vetW;

// funcao que atualiza a fila de prioridades
void atualizaFila(int u)
{
    explorado[u] = 1;
    for(int j = 0; j < LA[u].size(); j++)
    {
        ii v = LA[u][j];
        if(!explorado[v.first])
          /* valor: peso; chave: id do vertice
           * o valor negativo se deve ao fato de
           * que a heap do C++ eh implementada como
           * uma heap-max, e para desempate, prioriza-se
           * aqui o id de menor indice
           */
          Q.push(ii(v.second, v.first)); 
    }
}

int prim()
{
    explorado.assign(n, 0);
    atualizaFila(a);
    
    // custo da AGM
    int resultado = 0;
 
    // peso de uma aresta em cada iteracao
    int w;

    while(!Q.empty())
    {
        ii u = Q.top(); // O(1)
        Q.pop(); // O(logm)

        int w = u.first; // retirando o negativo cadastrado na heap
        int v = u.second;
     
        if(!explorado[v])
        {
            cout << w << endl;
            vetW.push_back(w);
            atualizaFila(v); // O(logm)
        }

        if(explorado[b]){
          cout<<"aqui";
            resultado = vetW[0];
            for(int i = 0; i < vetW.size(); i++){
                if(vetW[i] < resultado){
                    resultado = vetW[i];
                }
            }
            return resultado;
        }
    }
    cout<<"aqui";
    resultado = vetW[0];
        for(int i = 0; i < vetW.size(); i++){
            if(vetW[i] < resultado){
                resultado = vetW[i];
            }
        }
    return resultado;
}

int main()
{
    cin >> n >> m;
 
    for(int i = 0; i < n; i++)
    {
        vii lista;
        LA.push_back(lista);
    }
        
    int u, v, w; // extremos das arestas, e peso de cada aresta
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        int contador = 0, continua = 0;
        for(vector<vii>::iterator it = LA.begin(); it != LA.end() && continua < 2; ++it)
        {
          if(contador == u) 
          {
            ii par1(v, w);
            (*it).push_back(par1);    
            continua++;
          }
       
          else if(contador == v)
          {
            ii par2(u, w);
            (*it).push_back(par2);    
            continua++;
          }
          contador++;
      }
    }

    float qtd, resp = 0, temp;
    while(a != 0 && b != 0){
        cin >> a >> b;
        if(a != 0 && b != 0){
            cin >> qtd;
        }

        temp = prim();
        cout<<"aquimain"<<endl;
        if(temp >= 24){
            resp = qtd / 24;
        } else if (temp < 24){
            resp = qtd / temp;
        }       
    cout << ceil(resp) << endl;
    }

    return 0;
}