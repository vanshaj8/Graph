#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

// TOPOLOGICAL SORT IS POSSIBLE FOR DAG and it states that if there is 
// an edge from u to v then u should appear before v;

void dfs(int node,vector<int>adj[],vector<int>&vis,stack<int>&st)
	{
	    vis[node]=1;
	    for(auto it: adj[node])
	    {
	        if(!vis[it])
	        {
	            dfs(it,adj,vis,st);
	        }
	    }
	    st.push(node);
	}
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    vector<int>vis(n,0);
	    stack<int>st;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(vis[i]==0)
	        {
	            dfs(i,adj,vis,st);
	        }
	    }
	    vector<int>topo;
	    while(!st.empty())
	    {
	        topo.push_back(st.top());
	        st.pop();
	    }
	    return topo;
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
	
	topoSort(n,adj);
	return 0;
}
