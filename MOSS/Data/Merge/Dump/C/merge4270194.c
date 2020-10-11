#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAX 500010
#define inf 2000000000
int A[MAX],cnt=0;
int l[MAX/2+10],r[MAX/2+10];
void merge(int left,int mid,int right)
{
	int i,Lstart=1,Rstart=1;
	int n1=mid-left;
	int n2=right-mid;
	for(i=1;i<=n1;i++)
		l[i]=A[left+i-1];
	for(i=1;i<=n2;i++)
		r[i]=A[mid+i-1];
	l[n1+1]=inf;
	r[n2+1]=inf;
	for(i=left;i<=right-1;i++)
	{
		cnt++;
		if(l[Lstart]<=r[Rstart])
		{
			A[i]=l[Lstart];
			Lstart++;
		}
		else
		{
			A[i]=r[Rstart];
			Rstart++;
		}
	}
	return;
}
void mergesort(int left,int right)
{
	if(left+1>=right)
		return;
	int mid=(left+right)/2;
	mergesort(left,mid);
	mergesort(mid,right);
	merge(left,mid,right);
	return;
}
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	mergesort(1,n+1);
	for(i=1;i<n;i++)
		printf("%d ",A[i]);
	printf("%d\n%d\n",A[n],cnt);
	return 0;
}
