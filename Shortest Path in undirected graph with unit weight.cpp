#include<bits/stdc++.h>
#include<vector>
using namespace std;

void shortestPath(int src,int n, vector<int>adj[])
{
	int dist[n];
	for(int i=0;i<n;i++) dist[i]=INT_MAX;
	
	queue<int>q;
	dist[src]=0;
	q.push(src);
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto it: adj[node])
		{
			if(dist[node]+1<dist[it])
			{
				dist[it]=dist[node]+1;
				q.push(it);
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<dist[i]<<" ";
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>adj[n];
	
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	 } 
	 
	 shortestPath(0,n,adj);
	return 0;
}
