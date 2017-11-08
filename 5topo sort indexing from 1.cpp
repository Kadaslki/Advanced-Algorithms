#include "bits/stdc++.h"

using namespace std;

vector<vector <int> > adj;

void dfs(stack<int> &, int, vector<bool> &);

int main()
{
 int n, e, u, v;
 stack<int> s1;
 cin>>n>>e;
 vector<bool> visited(n+1, false);
 adj.resize(n+1);
 for(int i=0; i<e; i++)
 {
  cin>>u>>v;
  adj[u].push_back(v);
 };
 for(int i=1; i<=n; i++)
 {
  if(!visited[i])
   dfs(s1, i, visited);
 }
 cout<<endl<<endl;
 while(!s1.empty())
 {
  cout<<s1.top()<<" ";
  s1.pop();
 }
 cout<<endl;
}

void dfs(stack<int> &s1, int src, vector<bool> &visited)
{
 if(!visited[src])
 {
  visited[src]=true;
  vector<int> ::iterator i;
  for(i=adj[src].begin(); i!=adj[src].end(); i++)
  {
   if(!visited[*i])
   {
    dfs(s1, *i, visited);
   }
  }
  s1.push(src);
 }
}
