#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, u, v;
	
	cout<<"\nEnter number of vertices: ";
	cin>>n;
	
	vector< vector<int> > adj(n, vector<int>(n, INT_MAX));
	
	for(int i=0; i<n; i++)
		adj[i][i]=0;
		
	cout<<"\nEnter number of edges: ";
	cin>>m;
	
	for(int i=0; i<m; i++)
	{
		cout<<"\nEnter u and v: ";
		cin>>u>>v;
		cout<<"\nEnter edge weight: ";
		cin>>adj[u][v];
	}
	
	for(int k=0; k<n; k++)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(adj[i][k]+adj[k][j]<adj[i][j])
					adj[i][j]=adj[i][k]+adj[k][j];
			}
		}
	}
	
	cout<<"\nFinal distances: \n";
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout<<adj[i][j]<<" ";
		cout<<endl;
	}
}
