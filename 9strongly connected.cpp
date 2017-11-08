#include<bits/stdc++.h>

using namespace std;

void dfs(stack<int> &, int, vector<bool> &, vector< vector<int> > &);

int main()
{
	int src, n, min, u, t, m;
	
	cout<<"\nEnter number of vertices: ";
	cin>>n;
	cout<<"\nEnter source vertex: ";
	cin>>src;
	
	vector< vector<int> > alist(n), tlist(n);
	
	cout<<"\nEnter number of edges: ";
	cin>>m;
	
	for(int i=0; i<m; i++)
	{
	 cout<<"\nEnter u and v: ";
	 cin>>u>>t;
	 alist[u].push_back(t);
	 tlist[t].push_back(u);
	}
		
	stack<int> s, s1;
	vector<bool> visited(n, false);
	
	dfs(s, src, visited, alist);
	
	fill(visited.begin(), visited.end(), false);
	
	while(!s.empty())
	{
		cout<<endl;
		u=s.top();
		dfs(s1, u, visited, tlist);
		while(!s1.empty())
		{
			cout<<s1.top()<<' ';
			s1.pop();
		}
		s.pop();
	}
	cout<<endl;
}

void dfs(stack<int> &s1, int src, vector<bool> &visited, vector< vector<int> > &alist)
{
 if(!visited[src])
 {
  visited[src]=true;
  vector<int> ::iterator i;
  for(i=alist[src].begin(); i!=alist[src].end(); i++)
  {
   if(!visited[*i])
   {
    dfs(s1, *i, visited, alist);
   }
  }
  s1.push(src);
 }
}
