#include<bits/stdc++.h>
#include<vector>
using namespace std;

void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int> & dfss)
{
	dfss.push_back(node);
	vis[node]=1;
	
	for(auto it: adj[node])
	{
		if(!vis[it])
		{
			dfs(it,adj,vis,dfss);
		}
	}
}
void dfsofgraph(int V,vector<int>adj[])
{
	vector<int>vis(V+1,0);
	vector<int>dfss;
	dfs(0,adj,vis,dfss);
	
	for(int i=0;i<dfss.size();i++)
	{
		cout<<dfss[i]<<" ";
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
	dfsofgraph(n,adj);
	return 0;
}
