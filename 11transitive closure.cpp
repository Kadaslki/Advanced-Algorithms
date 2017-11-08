#include <bits/stdc++.h>

using namespace std;

void dfs(int, int, vector< vector<int> > &, vector< vector<int> > &);

int main()
{
	int n;
	
	cout << "\nEnter the number of nodes: ";
	cin >> n;
	
	vector< vector<int> > graph(n), reach(n, vector<int>(n, 0));	
			
	int e, u, v;
	
	cout << "\nEnter number of edges: ";
	cin >> e;
	
	for(int i = 0; i < e; i++)
	{
		cout << "\nEnter u and v: ";
		cin >> u >> v;
		graph[u].push_back(v);
	}
	
	for(int i = 0; i < n; i++)
	{
		dfs(i, i, graph, reach);
	}
	
	cout << endl << endl;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << reach[i][j] << " ";
		}
		
		cout << endl;
	}
}

void dfs(int s, int v, vector< vector<int> > &graph, vector< vector<int> > &reach)
{
	reach[s][v] = 1;
	
    vector<int> ::iterator i;
  	for(i = graph[v].begin(); i != graph[v].end(); i++)
  	{
   		if(reach[s][*i] == 0)
   		{
    		dfs(s, *i, graph, reach);
   		}
	}
}
	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
