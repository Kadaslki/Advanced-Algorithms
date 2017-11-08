#include<bits/stdc++.h>

using namespace std;

int main(){

int n,e;

cout<<"Enter number of vertices: ";

cin>>n;

cout<<"Enter number of edges: ";

cin>>e;
int h[n];
cout<<"Enter vertex weights: "<<endl;

for(int i=0;i<n;i++)

cin>>h[i];

vector<vector<pair<int,int> > > g(n);

int u,v,w;

cout<<"Enter graph:"<<endl;

for(int i=0;i<e;i++){

cin>>u>>v>>w;

g[u].push_back(make_pair(v,w + h[u]-h[v]));

}

for(int i=0;i<n;i++){

priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; vector<int> dist(n);

for(int j=0;j<n;j++)

dist[j] = INT_MAX;

dist[i] = 0;

pq.push(make_pair(dist[i],i));

while(!pq.empty()){

pair<int,int> t = pq.top();

pq.pop();
int u = t.second;
for(int k=0;k<g[u].size();k++){

int v = g[u][k].first;

int w = g[u][k].second;
if(dist[v] > dist[u]+w){

dist[v] = dist[u] + w;

pq.push(make_pair(dist[v],v));

}

}

}


cout<<"shortest distance from source "<<i<<":"<<endl;

for(int j=0;j<n;j++){

if(dist[j]==INT_MAX)

cout<<"inf ";

else

cout<<dist[j]+(h[j]-h[i])<<" ";

}

cout<<endl;

}

}
