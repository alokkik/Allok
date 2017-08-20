#include<bits/stdc++.h>
#define N 100001
using namespace std;
int dis[N];
int visit[N];
vector<pair<int,int> > graph[N];
typedef pair<int,int> _pair;
void init()
{
	for(int i=0;i<=N;i++)
		dis[i]=INT_MAX;
	for(int i=0;i<=N;i++)
		visit[i]=0;
}
void dijkshtra(int src,int n)
{
	init();
    dis[src]=0;
    priority_queue<_pair,vector<_pair>,greater<_pair> > q;
    q.push(make_pair(0,src));   // in priority_queue first is dis
    while(!q.empty())           // second is vertex 
    {
        pair<int,int> a=q.top();
        int x=a.second,y=a.first;
        q.pop();
        if(visit[x])
            continue;
        visit[x]=true;
        for(int i=0;i<graph[x].size();i++)
        {
        	
            int p=graph[x][i].first;
            int w=graph[x][i].second;
            if(dis[x]+w<dis[p])
            dis[p]=dis[x]+w;
            q.push(make_pair(dis[p],p));
        }
    }
}
int main()
{
    int n,m,x,y,w;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        graph[x].push_back(make_pair(y,w));
        graph[y].push_back(make_pair(x,w));
    }
    dijkshtra(1,n);
return 0;
}
