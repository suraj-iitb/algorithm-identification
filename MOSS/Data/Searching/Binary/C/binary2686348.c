#include <stdio.h>
int search(int key,int S[],int n)
{
	int low=0,high=n,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(S[mid]==key)	
		return 1;
		else if(S[mid]<key)
		low=mid+1;
		else
		high=mid-1;
	}
	return 0;
}
int main(int argc, char *argv[])
{
	int S[100000],n,k,q,i,count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&S[i]);
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d",&k);
		if(search(k,S,n))
		count++; 
	}
	printf("%d\n",count);
	return 0;
}


