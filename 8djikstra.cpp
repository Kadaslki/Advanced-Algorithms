#include<bits/stdc++.h>

using namespace std;

int main()
{
	int src, n, min, u, t, m;
	
	cout<<"\nEnter number of vertices: ";
	cin>>n;
	cout<<"\nEnter source vertex: ";
	cin>>src;
	
	vector< vector<int> > adj(n, vector<int>(n, -1));
	
	cout<<"\nEnter number of edges: ";
	cin>>m;
	
	for(int i=0; i<m; i++)
	{
	 cout<<"\nEnter u and v: ";
	 cin>>u>>t;
	 cout<<"\nEnter edge weight: ";
	 cin>>adj[u][t];
	 adj[t][u]=adj[u][t];
	}
	
			
	set<int> spt, visited;
	vector<int> dist(n, INT_MAX);
	
	dist[src]=0;
	u=src;
	spt.insert(spt.end(), u);
	
	while(spt.size()!=n)
	{
		min=INT_MAX;
		for(int i=0; i<n; i++)
		{
			if(adj[u][i]!=-1&&spt.find(i)==spt.end())
			{
				if(dist[i]>dist[u]+adj[u][i])
				{
					dist[i]=dist[u]+adj[u][i];
					visited.insert(visited.end(), i);
				}
			}
		}
		for(set<int>::iterator i=visited.begin(); i!=visited.end(); i++)
		{
			if(min>dist[*i])
			{
				min=dist[*i];
				t=*i;
			}
		}
		u=t;
		spt.insert(spt.end(), u);
		visited.erase(visited.find(u));
	}
	cout<<"\nDistances from vertex "<<src<<": ";
	for(int i=0; i<n; i++)
	{
		cout<<dist[i]<<"  ";
	}
	cout<<"\n\n";
}
