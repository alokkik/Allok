#include<bits/stdc++.h>
#define N 101
using namespace std;
vector<int> tree[N];
int depth[N];
int parent[N];
int jump_parent[N];
int max_depth=0;
void height(int start)
{
	if(!tree[start].size())
		{
			max_depth=max(max_depth,depth[start]);
			return;
		}
	for(int i=0;i<tree[start].size();i++)
			{
			parent[tree[start][i]]=start;
			depth[tree[start][i]]=depth[start]+1;
			height(tree[start][i]);
			}
}
void dfs(int node)
{
	int b_size=sqrt(max_depth);
	if(depth[node]%b_size==0)
		jump_parent[node]=parent[node];
	else
		jump_parent[node]=jump_parent[parent[node]];
	for(int i=0;i<tree[node].size();i++)
			dfs(tree[node][i]);
return;
}
int lca(int a,int b)
{
	while(jump_parent[a]!=jump_parent[b])
	{
		if(depth[a]>depth[b])
			a=jump_parent[a];
		else
			b=jump_parent[b];
	}
	while(a!=b)
	{
		if(depth[a]>depth[b])
			a=parent[a];
		else
			b=parent[b];
	}
return a;
}
int main()
{
	int n,x,y;
	cin>>n;
	for(int i=0;i<n-1;i++)
		{
			cin>>x>>y;
			tree[x].push_back(y);
		}
	depth[1]=0;
	parent[1]=1;	// taking one as a root
	height(1);
	dfs(1);
	cout<<lca(8,9)<<"\n"<<lca(9,7)<<"\n";
return 0;
}
