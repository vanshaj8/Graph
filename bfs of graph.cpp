#include<bits/stdc++.h>
#include<vector>
using namespace std;
void bfsOfGraph(int v, vector<int> adj[])
	{
	    vector<int>bfs;
	    queue<int>q;
	    vector<int>vis(v+1,0);
	    q.push(0);
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        vis[node]=1;
	        bfs.push_back(node);
	        
	        for(auto it: adj[node])
	        {
	            if(!vis[it])
	            {
	                q.push(it);
	                vis[it]=1;
	            }
	        }
	    }
	    
	    for(int i=0;i<bfs.size();i++)
	    {
	    	cout<<bfs[i]<<" ";
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
	bfsOfGraph(n,adj);
	return 0;
}
