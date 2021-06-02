#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

bool detectCycle(int s,int V,vector<int>adj[],vector<int>&vis)
{
	queue<pair<int,int>>q;
	vis[s]=true;
	q.push({s,-1});
	
	while(!q.empty())
	{
		int node=q.front().first;
		int parent=q.front().second;
		q.pop();
		
		for(auto it: adj[node])
		{
			if(!vis[it])
			{
				q.push({it,node});
				vis[it]=true;
			}
			else if(parent!=it) return true;
		}
	}
	return false;
}
bool isCycle(int V,vector<int>adj[])
{
	vector<int>vis(V,0);
	for(int i=0;i<V;i++)
	{
		if(!vis[i])
		{
			if(detectCycle(i,V,adj,vis))
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
