#include <bits/stdc++.h>
using namespace std;

int main(){
  	int n, e, u, v;
  	cout << "\nEnter number of vertices and edges: ";
  	cin >> n >> e;
  	vector< vector< int > > m(n, vector<int>(n, 0)), t(n, vector<int>(n, 0));
  	for(int i = 0; i < e; i++){
      		cout << "\nEnter u and v: ";
      		cin >> u >> v;
      		m[u][v] = 1;
      		t[v][u] = 1;
  	}
  	cout << "\n\n\t\t**Original Graph**\n\n";
  	for(int i = 0; i < n; i++){
      		for(int j = 0; j < n; j++)
        			cout << m[i][j] << " ";
      		cout << endl;
  	}
  	cout << "\n\n\t\t**Transpose Graph**\n\n";
  	for(int i = 0; i < n; i++){
      		for(int j = 0; j < n; j++)
        			cout << t[i][j] << " ";
      		cout << endl;
  	}
}
