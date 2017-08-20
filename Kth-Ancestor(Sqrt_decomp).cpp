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
int kth_ancestor(int x,int k)
{
	int b_size=sqrt(max_depth);
	while(k>b_size&&(depth[x]%b_size!=(b_size-1)))
		{
			x=parent[x];
			k--;
		}
	while(k>=b_size)
	{
		x=jump_parent[x];
		k-=b_size;
	}
	while(k>0)
	{
		x=parent[x];
		k--;
	}
return x;
}
int main()
{
	int n,x,y;
	cin>>n;
	for(int i=0;i<n;i++)
		{
			cin>>x>>y;
			tree[x].push_back(y);
		}
	depth[1]=0;
	parent[1]=1;	// taking one as a root
	height(1);
	dfs(1);
	cout<<"\n"<<kth_ancestor(15,10)<<"\n";
return 0;
}
