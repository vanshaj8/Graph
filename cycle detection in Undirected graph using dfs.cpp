#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
bool detectCycle(int node,int parent, vector<int> adj[],vector<int>& vis)
{
	vis[node]=1;
	for(auto it: adj[node])
	{
	    if(!vis[it])
		{
			if(detectCycle(it,node,adj,vis)) return true;  
		}
		else if(it!=parent) return true;	
	}
	
	return false;
}
bool isCycle(int V,vector<int> adj[])
{
	vector<int>vis(V,0);
	
	for(int i=0;i<V;i++)
	{
		if(!vis[i])
		{
			if(detectCycle(i,-1,adj,vis))
			{
				return true;
			}
		}
	}
	return false;
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
	cout<<isCycle(n,adj);
	return 0;
}
