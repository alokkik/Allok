// All about segment tree in this file
#include<bits/stdc++.h>
#define N 100
using namespace std;
int t[2*N];
int d[N]; //delay or lazy array
int n;
void input()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>t[n+i];
}
void build_tree(int node,int low,int high)
{
	if(low==high)
		return;
	else
		{
			int mid=(low+high)/2;
			build_tree(2*node,low,mid);
			build_tree(2*node+1,mid+1,high);
			t[node]=t[2*node]+t[2*node+1];
		}
}
void update(int node,int low,int high,int idx,int value)
{
	if(low==high) // leaf node condition
	{
		if(low==idx) // if leaf is target index 
			{
				t[node]+=value;
				t[idx]+=value;
			}
		return;
	}
	else
	{
	int mid=(low+high)/2;
	if(idx<=mid) //check if to go left or right
		update(2*node,low,mid,idx,value);
	else
		update(2*node+1,mid+1,high,idx,value);
	    t[node]=t[2*node]+t[2*node+1];
	}
}
void update_range_instantly(int node,int low,int high,int l,int r,int value)
{
	if(low>high||low>r||high<l)
		return;
	if(low==high)
		{
		t[low]+=value;return;
		}
	int mid=(low+high)/2;
	update_range_instantly(2*node,low,mid,l,r,value);
	update_range_instantly(2*node+1,mid+1,high,l,r,value);
	t[node]=t[2*node]+t[2*node+1];
}
void update_range_lazy(int node,int low,int high,int l,int r,int value)
{
	if(high<low||low>r||high<l) // base case
		return;
	if(d[node])	// checking current node for any pending update
	{
		t[node]+=(high-low+1)*d[node];
		if(low!=high)
		{
			d[2*node]+=d[node];
			d[2*node+1]+=d[node];
			d[node]=0;
		}
	}
	if(low>=l&&high<=r)   //if we update internal node then
	{						// we have to propagate changes to its
		t[node]+=(high-low+1)*value; // child nodes 
		if(low!=high)
		{
			d[2*node]+=value;
			d[2*node+1]+=value;
		}
	return;
	}
	int mid=(low+high)/2;
	update_range_lazy(2*node,low,mid,l,r,value);
	update_range_lazy(2*node+1,mid+1,high,l,r,value);
	t[node]=t[2*node]+t[2*node+1];
}
int query(int node,int low,int high,int l,int r)
{
	if(low>high||low>r||high<l)
		return 0;
	if(d[node])
	{
		if(low!=high)
		{
			d[2*node]+=d[node];
			d[2*node+1]=d[node];
			d[node]=0;
		}
	}
	if(low>=l&&high<=r)
		return t[node];
	int mid=(low+high)/2;
	int num=query(2*node,low,mid,l,r);
	int num1=query(2*node+1,mid+1,high,l,r);
return num+num1;
}
void print()
{
	for(int i=1;i<2*n;i++)
		cout<<t[i]<<" ";
	cout<<"\n";
}
int main()
{
	input();
	build_tree(1,n,2*n-1);
	update_range_lazy(1,n,2*n-1,n,2*n-1,100);
	query(1,n,2*n-1,n,2*n-1);
	update_range_lazy(1,n,2*n-1,n,2*n-1,200);
	query(1,n,2*n-1,n,2*n-1);
	print();
return 0;	
}
