#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


bool checkBipartite(int src,int V,vector<int>adj[],int color[])
{
	queue<int>q;
	q.push(src);
	color[src]=1;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto it : adj[node])
		{
			if(color[it]==-1)
			{
				color[it]=1-color[node];
				q.push(it);
			}
			else if(color[it]==color[node]) return false;
		}
	}
	return true;
}
bool isBipartite(int V,vector<int>adj[])
{
	int color[V];
	memset(color,-1,sizeof color);
	for(int i=0;i<V;i++)
	{
		if(!color[i]==-1)
		{
		      if(!checkBipartite(i,-1,adj,color));
		      {
		      	return false;
			  }
		}
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
	cout<<isBipartite(n,adj);
	return 0;
}
