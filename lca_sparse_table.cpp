#include<bits/stdc++.h>
#define N 100001
#define MAXLOG floor(log2(N))
using namespace std;
int ancestor[N][MAXLOG];
int tree[N];
int parent[N];
int depth[N];
void dfs(int start)
{
	for(int i=0;i<tree[start].size();i++)
		{
			parent[tree[start][i]]=start;
			depth[tree[start][i]]=depth[start]+1;
			dfs(tree[start][i]);
		}
return;
}
void preprocessing()
{
    // below here,for every node its 2^jth ancestor is initialized to -1
    for(int i=1;i<=N;i++)
        for(int j=0;(1<<j)<N;j++)
            ancestor[i][j]=-1;
    // for every node its 2^0 th ancestor will be its parent
    for(int i=1;i<=N;i++)
        ancestor[i][0]=parent[i];
    // for every node its 2^jth ancestor can be obataind by
    // finding 2^(j-1)th ancestor of 2^(j-1)th ancestor of i
    for(int i=1;i<=N;i++)
        for(int j=0;(1<<j)<N;j++)
            if(ancestor[i][j-1]!=-1)//
                ancestor[i][j]=ancestor[ancestor[i][j-1]][j-1];
}
int lca(int a,int b)
{
	if(depth[a]>depth[b])
		swap(a,b);
	while(depth[a]!=depth[b])
	{
		for(int j=MAXLOG;j>=0;j--)
            if(ancestor[b][j]!=-1&&depth[a]<depth[ancestor[b][j]])
                b=ancestor[b][j];
	}
    if(a==b)
        return a;
    for(int i=MAXLOG;i>=0;i--)
    	if(ancestor[a][i]!=-1&&ancestor[a][i]!=ancestor[b][i])
    		{
    			a=ancestor[a][i];
    			b=ancestor[b][i];
    		}
return ancestor[a];
}
int main()
{
	int n,x,y;
	cin>>n
	for(int i=0;i<n-1;i++)
		{
			cin>>x>>y;
			tree[x].push_back(y);
		}
	depth[root]=0;
	cin>>a>>b;
	cout<<lca(a,b);
return 0;
}
