#include<bits/stdc++.h>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int parent[100000];
int rank[100000];
void makeset(int n)
{
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
		rank[i]=0;
	}
}

int findpar(int node)
{
	if(node==parent[node])
	{
		return node;
	}
	
	return parent[node]=findpar(parent[node]); // the step of compression
}
void union(int u,int v)
{
	u=findpar(u);
	v=findpar(v);
	
	if(rank[u]<rank[v])
	{
		parent[u]=v;
	}
	else if(rank[u]>rank[v])
	{
		parent[v]=u;
	}
	else
	{
		parent[v]=u;
		rank[u]++;
	}
}
int main()
{
	int n;
	cin>>m;
	return 0;
}
