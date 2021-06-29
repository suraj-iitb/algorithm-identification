#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int S[100010],T[50010],n,q;
int binarysearchS(int left,int right,int t)
{
	if(left>right)
		return 0;
	int mid;
	mid=left+right;
	mid/=2;
	if(S[mid]==t)
		return 1;
	if(S[mid]>t)
		return binarysearchS(left,mid-1,t);
	return binarysearchS(mid+1,right,t);
}
int main()
{
	int C=0,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&S[i]);
	scanf("%d",&q);
	for(i=1;i<=q;i++)
		scanf("%d",&T[i]);
	for(i=1;i<=q;i++)
		C+=binarysearchS(1,n,T[i]);
	printf("%d\n",C);
	return 0;
}
