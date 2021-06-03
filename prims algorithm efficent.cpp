#include<bits/stdc++.h>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int main()
{
	int n,m;
	cin>>n >> m;
	vector<pair<int ,int> > adj[n];
	for(int i=0;i<m;i++)
	{
		int u,v,wt;
		cin>> u >> v >> wt;
		adj[u].push_back({v,wt});
		adj[v].push_back({u,wt});
	}
	
	int parent[n];
	bool mst[n];
	int key[n];
	
	for(int i=0;i<n;i++)
	{
		key[i]=INT_MAX;
		mst[i]=false;
	}
	
	// creating a heap to remove the loop which points directly to the minimum node

    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
	 key[0]=0;
	 parent[0]=-1;
	 pq.push({0,0}); // pq.first is the key node for minimum values and pq.second is the node itself
	 
	 while(!pq.empty())
	 {
	 	int u=pq.top().second; // the node
	 	pq.pop();
	 	 mst[u]=true;
	 	 
	 	 for(auto it : adj[u])
	 	 {
	 	 	int v=it.first;
	 	 	int weight=it.second;
	 	 	
	 	 	if(mst[v]==false && weight<key[v])
	 	 	{
	 	 		parent[v]=u;
	 	 		key[v]=weight;
	 	 		pq.push({key[v],v});
			}
		 }
	 }
	 for (int i = 1; i < n; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}
