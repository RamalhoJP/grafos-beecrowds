/*
Dupla: Gustavo Biaso Dias Pinto 202210925 e João Pedro Ramalho de Sousa 202210443
Turma 10A
*/
#include<iostream>

using namespace std;

int main(){
  int n, m; // numero de vertices; numero de arestas do grafo

	cin >> n;

	while(n != -1){
		cin >> m;

		int** M = new int*[n]; // matriz de adjacencia
		for(int i = 0; i < n; i++){
			M[i] = new int[n];
		}
	
		for(int u = 0; u < n; u++)
			for(int v = 0; v < n; v++)
				M[u][v] = 0;
		
		// leitura do grafo
		int u, v;

		for(int i = 0; i < m; i++){
			cin >> u >> v; 
			M[u][v] = M[v][u] = 1;
		}

		int** Maux = new int*[n];
		int** Mresult = new int*[n];
		for(int i = 0; i < n; i++){
			Maux[i] = new int[n];
			Mresult[i] = new int[n];
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				Maux[i][j] = M[i][j];
				Mresult[i][j] = 0;
			}
		}

		int a, b, o, ka;
		cin >> o >> ka;

		for(int i = 1; i < ka; i++){
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					for(int l = 0; l < n; l++){
						Mresult[j][k] += Maux[j][l] * M[l][k];
						a = Mresult[j][k];
					}
				}
			}
			if(i < ka-1){
				for(int i = 0; i < n; i++){
					for(int j = 0; j < n; j++){
						Maux[i][j] = Mresult[i][j];
						Mresult[i][j] = 0;
					}
				}
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << Mresult[i][j] << " "; 
			}
			cout << endl;
		}
		
		for(int i = 0; i < o; i++){
			cin >> a >> b;
			cout << Mresult[a][b];
			if(i < o-1){
				cout << endl;
			}
		}

		for(int u = 0; u < n; u++){
			delete M[u];
			delete Maux[u];
			delete Mresult[u];
		}
		delete[] M;
		delete[] Maux;
		delete[] Mresult;

		cin >> n;
		if(n > -1){
			cout<< endl;
		}
	}
       
  	return 0;
}