#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


bool checkBipartite(int node,vector<int>adj[],int color[])
{
	if(color[node]==-1)
	{
		color[node]=1;
	}
	for(auto it:adj[node])
	{
		if(color[it]==-1)
		{
			color[it]=1-color[node];
			if(!checkBipartite(it,adj,color)) return false;
		}
		else if(color[it]==color[node])return false;
	}
	return true;
}
bool isBipartite(int V,vector<int>adj[])
{
	int color[V];
	memset(color,-1,sizeof color);
	
	for(int i=0;i<V;i++)
	{
		if(color[i]==-1)
		{
			if(!checkBipartite(i,adj,color))
			{
				return false;
			}
		}
	}
	return true;
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
	cout<<isBipartite(n,adj);
	return 0;
}
