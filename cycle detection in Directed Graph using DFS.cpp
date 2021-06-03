#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

bool checkCycle(int node,vector<int>adj[],int vis[],int vdfs[])
{
	vis[node]=1;
	vdfs[node]=1;
	for(auto it:adj[node])
	{
		if(!vis[it])
		{
			if(checkCycle(it,adj,vis,vdfs)) return true;
		}else if(vdfs[it]) return true;
	}
	vdfs[node]=0;
	return false;
}
bool isCycle(int V,vector<int>adj[])
{
	int vis[V],vdfs[V];
	memset(vis,0,sizeof vis);
	memset(vdfs,0,sizeof vdfs);
	
	for(int i=0;i<V;i++)
	{
		if(!vis[i])
		{
			if(checkCycle(i,adj,vis,vdfs)) return true;
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
	}
	
	cout<<isCycle(n,adj)<<endl;
	return 0;
}
