#include "bits/stdc++.h"

using namespace std;

void dfs(stack<int> &, int, vector<bool> &, vector< vector<int> > &);

int main()
{
 	int n, e, u, v, s, w;
 	stack<int> s1;
	
	cout << "\nEnter number of vertices and edges: "; 	
	cin >> n >> e;
	cout << "\nEnter source: ";
	cin >> s;
	
	vector<vector <int> > adjm(n, vector<int>(n, INT_MAX)), adjl(n);
	vector<bool> visited(n, false);
	vector<int> dist(n, INT_MIN);
	dist[s] = 0;

	for(int i = 0; i < e; i++){
		cout << "\nEnter u, v and w: ";
		cin >> u >> v >> w;
	    adjm[u][v] = w;
	    adjl[u].push_back(v);
	}
	
	for(int i = 0; i < n; i++){
	    if(!visited[i])
	    dfs(s1, i, visited, adjl);
	}
	
	cout << endl << endl;
	
	while(!s1.empty()){
		int curr = s1.top();
		if(dist[curr] != INT_MAX){
			for(int i = 0; i < n; i++){
				if((dist[i] < dist[curr] + adjm[curr][i]) && (adjm[curr][i] != INT_MAX))
					dist[i] = dist[curr] + adjm[curr][i];
			}
		}
		s1.pop();
	}
	
	for(int i = 0; i < n; i++){
		if(dist[i] == INT_MAX){
			cout << "inf ";
		}
		else
			cout << dist[i] << " ";
	}
	
	cout << endl;

}
	
void dfs(stack<int> &s1, int src, vector<bool> &visited, vector< vector<int> > &adj)
{
 	if(!visited[src])
	 {
	  	visited[src] = true;
	  	vector<int> ::iterator i;
	  	for(i = adj[src].begin(); i != adj[src].end(); i++){
	   		if(!visited[*i]){
	   			dfs(s1, *i, visited, adj);
	   		}
	  	}
	  	s1.push(src);
	 }
}
