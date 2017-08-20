
//Program for RMQ using SquareRootDecomposition
#include<bits/stdc++.h>
using namespace std;
void update(int* arr,int* decomp,int idx,int value,int n)
{
	int block_size=sqrt(n);
	arr[idx]=value;
	if(arr[idx]<arr[decomp[idx/block_size]])
			decomp[idx/block_size]=idx;
}
void preprocess_for_rmq(int* arr,int* decomp,int n)
{
	int block=-1;
	int block_size=sqrt(n);
	for(int i=0;i<n;i++)
	{
		if(i%block_size==0)
			block++;
		if(arr[decomp[block]]>arr[i])
				decomp[block]=i;
	}
}
int query_for_min(int* arr,int* decomp,int l,int r,int n)
{
	int block_size=sqrt(n);
	int mini=INT_MAX;
		while(l&&(l%block_size)&&l<=r)
			{
				mini=min(mini,arr[l]);l++;
			}
		while(l+block_size<=r)
			{	
				mini=min(mini,arr[decomp[l/block_ize]])
				l+=block_size;
			}
		while(l<=r)
		{
			mini=min(mini,arr[l]);l++;
		}
return mini;
}
int main()
{
	int arr[]={1, 5, 2, 4, 6, 1, 3, 5, 7, 10};
	int n=sizeof(arr)/sizeof(arr[0]);
	int decomp[sqrt(n)];
	preprocess_for_rmq(arr,decomp,n);
	cout<<query(1,4);
return 0;
}
