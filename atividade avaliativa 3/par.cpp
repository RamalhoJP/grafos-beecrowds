#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<functional>
using namespace std;

#define INF 100000000

/*
 * Variaveis globais
 */

// lista de adjacencia
vector<pair<int, double>>* LA;

// numero de vertices do grafo
int n;

// numeor de arestas do grafo
int m;

// distancia da origem "org" a cada vertice do grafo
// first é PAR second é IMPAR
vector<pair<double, double>> d;

int dijkstra(int org){
    for(int i = 0; i < n; i++){
        d.push_back(make_pair(INF,INF));
    }
    // a distance da origem "org" eh sempre zero
    d[org].first = 0;
    
    // heap que auxilia na obtencao do vertice com maior prioridade, a cada iteracao
    priority_queue< pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>> > heap;
    
    // primeiro par inserido na heap: "org" com custo zero
    heap.push(make_pair(0, org));
 
    vector<bool> visitado;
    visitado.assign(n, false);

    // o algoritmo para quando a heap estiver vazia
    while(!heap.empty()){
        pair<double, int> vertice = heap.top();
        heap.pop();

        double distancia = vertice.first;
        int v = vertice.second;
        
        if(distancia > d[v].first and distancia > d[v].second){
            continue;
        }

        for(int j = 0; j < LA[v].size(); j++){
           pair<int, double> u = LA[v][j];
           int vizinho = u.first;
           double peso = u.second;

            // melhorar caminho impar : se a distancia par do atual + o peso de uv for menor que a distancia impar do vizinho
            if(d[v].first + peso < d[vizinho].second){
                d[vizinho].second = d[v].first + peso;
                heap.push(make_pair(d[vizinho].second, vizinho));
            }

            //melhorar caminho par : se a distancia impar do atual + o peso de uv for menor que a distancia par do vizinho
            if(d[v].second + peso < d[vizinho].first){
                d[vizinho].first = d[v].second + peso;
                heap.push(make_pair(d[vizinho].first, vizinho));
            }
        } 
    }
    for(int i = 0; i < n; i++){
        cout<< i << " " << d[i].first << " " << d[i].second << endl;
    }

    if(d[n-1].first == INF)
        return -1;
    
    return d[n-1].first;
}

int main(){
    cin >> n >> m;
   
    LA = new vector<pair<int, double>>[n];
    int u, v;
    double p;
    for(int i = 0; i < m; i++){
        cin >> u >> v; 
        cin >> p;
        u--;
        v--;
        LA[u].push_back(make_pair(v, p));
        LA[v].push_back(make_pair(u, p));
    }

    cout << dijkstra(0);

    return 0;
}