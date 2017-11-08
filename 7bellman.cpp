#include<bits/stdc++.h>

using namespace std;

struct Edge{
	int f;
	int s;
	int weight;
};

int main()
{
	int src, n, m, flag=0;
	
	cout<<"\nEnter number of vertices: ";
	cin>>n;
	cout<<"\nEnter source vertex: ";
	cin>>src;
	
	cout<<"\nEnter number of edges: ";
	cin>>m;
	
	vector<Edge> ez(m);
	
	for(int i=0; i<m; i++)
	{
	 cout<<"\nEnter u and v: ";
	 cin>>ez[i].f>>ez[i].s;
	 cout<<"\nEnter edge weight: ";
	 cin>>ez[i].weight;
	}
	
	vector<int> dist(n, INT_MAX);
	
	dist[src]=0;
	
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(dist[ez[j].s]>dist[ez[j].f]+ez[j].weight)
				dist[ez[j].s]=dist[ez[j].f]+ez[j].weight;
		}
	}
	for(int j=0; j<m; j++)
		{
			if(dist[ez[j].s]>dist[ez[j].f]+ez[j].weight)
			{
				flag=1;
				break;
			}
		}
	if(flag)
		cout<<"\nNegative edge cycle detected.\n";
	else if(!flag)
	{
		cout<<"\nDistance from vertex "<<src<<": ";
		for(int i=0; i<n; i++)
			cout<<dist[i]<<" ";
	}
	cout<<endl;
}

















