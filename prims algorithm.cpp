#include<bits/stdc++.h>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	int n,m;
	cin>> n >> m;
	vector<pair<int,int> >adj[n];
	for(int i=0;i<m;i++)
	{
		int u,v,wt;
		cin>>u >>v >> wt;
		adj[u].push_back({v,wt});
		adj[v].push_back({u,wt});
	}
	
	// make three 3 arrays one for keys(weight) mst(visited) and parent
	
	int parent[n];
	bool mst[n];
	int key[n];
	for(int i=0;i<n;i++)
	{
		key[i]=INT_MAX;
		mst[i]=false;
	}
	
	key[0]=0;
	parent[0]=0;
	int ansWeight=0;
	
	for(int count=0;count <n-1;count++) // because of n-1 edges 
	{
		int mini=INT_MAX,u; // mini is for the minimum value and u is the minimum value node
		// check for the minimum values
		for(int v=0;v<n;v++)
		{
			if(mst[v]==false && key[v]<mini)
			{
				mini=key[v];
				u=v;
			}
		for(auto it :adj[u])
		{
			int v=it.first;
			int weight=it.second;
			if(mst[v]==false && weight<key[v])
			{
				parent[v]=u;
				key[v]=weight;
			}
		}
	}
	
	for(int i=1;i<n;i++)
	{
		cout<<parent[i]<<" - "<<i<<"\n";
	}
	return 0;
}

}
