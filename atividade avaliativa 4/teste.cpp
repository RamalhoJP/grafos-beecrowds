#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> v;
  int n;
  for(int i = 0; i < 5; i++){
    cin >> n;
    v.push_back(n);
  }

  for(int i = 0; i < v.size(); i++){
    cout << v[i] << endl;
  }

  return 0;
}