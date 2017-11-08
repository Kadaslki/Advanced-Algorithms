#include "bits/stdc++.h"

using namespace std;

void dfs(int, vector<bool> , vector< vector<int> > &, bool &);

int main()
{
	bool f;
 	int n, e, u, v;
	cout << "\nEnter number of vertices and edges: "; 	
	cin >> n >> e;	
	vector<vector <int> > adjl(n);
	vector<bool> visited(n, false);

	for(int i = 0; i < e; i++){
		cout << "\nEnter u, v: ";
		cin >> u >> v;
	    adjl[u].push_back(v);
	}
	for(int i = 0; i < n; i++){
	    if(!visited[i])
	    	dfs(i, visited, adjl,f);
	}
	if(f==true)
		cout<<"\nNot a singly connected";
	else
		cout<<"\nSingly connected";
}
	
void dfs(int src, vector<bool> visited, vector< vector<int> > &adj, bool &f)
{
	f=false;
 	if(!visited[src])
	 {
	  	visited[src] = true;
	  	vector<int> ::iterator i;
	  	for(i = adj[src].begin(); i != adj[src].end(); i++){
	  		if(visited[*i])
	  			f=true;
	   		if(!visited[*i]){
	   			dfs(*i, visited, adj,  f);
	   		}
	  	}
	 }
}
