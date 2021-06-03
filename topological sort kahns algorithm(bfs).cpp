#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

// TOPOLOGICAL SORT IS POSSIBLE FOR DAG and it states that if there is 
// an edge from u to v then u should appear before v;

vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int>indegree(V,0);
	   for(int i=0;i<V;i++)
	   {
	       for(auto it :adj[i])
	       {
	           indegree[it]++;
	       }
	   }
	   queue<int>q;
	   
	   for(int i=0;i<V;i++)
	   {
	       if(indegree[i]==0)
	       {
	           q.push(i);
	       }
	   }
	   vector<int>topo;
	   while(!q.empty())
	   {
	       int node=q.front();
	       q.pop();
	       topo.push_back(node);
	       for(auto it: adj[node])
	       {
	           indegree[it]--;
	           if(indegree[it]==0)
	           {
	               q.push(it);
	           }
	       }
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
	
	findtopo(n,adj);
	return 0;
}
