#include <stdio.h>
#include <stdlib.h>
#define MAX 2000000000
int S[500005],n,count=0;
void Merge(int left,int mid,int right)
{
	int *q=(int *)malloc(sizeof(int)*(mid-left+1));
	int *p=(int *)malloc(sizeof(int)*(right-mid+1));
	int k,i,j;
	for(i=0;i<mid-left;i++)
	p[i]=S[i+left];
	for(i=0;i<right-mid;i++)
	q[i]=S[i+mid];
	p[mid-left]=q[right-mid]=MAX;
	i=j=0;
	for(k=left;k<right;k++)
	{
		if(q[i]>p[j])
		S[k]=p[j++];
		else
		S[k]=q[i++];
		count++;
	}
}
void MergeSort(int left,int right)
{
	if(left+1<right)
	{
		int mid=(left+right)/2;
		MergeSort(left,mid);
		MergeSort(mid,right);
		Merge(left,mid,right);
	}
}
int main(int argc, char *argv[])
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&S[i]);	
	MergeSort(0,n);
	for(i=0;i<n;i++)
	if(i+1==n)
	printf("%d\n%d\n",S[i],count);
	else
	printf("%d ",S[i]);
	return 0;
}
