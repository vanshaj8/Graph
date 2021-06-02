#include<bits/stdc++.h>
#include<vector>
using namespace std;

void findtoposort(int node,int vis[],stack<int>&st,vector<pair<int,int>adj[])
{
	vis[node]=1;
	for(auto it:adj[node])
	{
		if(!vis[it.first])
		{
			findtoposort(it,vis,st,adj);
		}
	}
	st.push(node);
}

void shortestPath(int src,int n,vector<pair<int,int>>adj[])
{
	int vis[n]={0}; // initalising the visited by 0
	
	stack<int>st;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			findtoposort(src,vis,st,adj);
		}
	}
	
	int dist[n];
	
}
int main()
{

   int n,m;
   cin>>n>m;
   vector<pair<int,int>>adj[n];
   
   for(int i=0;i<m;i++)
   {
       int u,v,wt;
	   cin>>u>>v>>wt;
	   adj[u].push_back({v,wt});	
   }	
	
	shortestPath(0,n,adj);
	return 0;
}
