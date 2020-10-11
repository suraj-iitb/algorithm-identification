#include<math.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int A[110],sw=0,n;
void swap(int x,int y)
{
	int t;
	t=A[x];
	A[x]=A[y];
	A[y]=t;
	sw++;
	return;
}
void selectionsort()
{
	int i,j,min;
	for(i=1;i<=n;i++)
	{
		min=i;
		for(j=i;j<=n;j++)
			if(A[j]<A[min])
				min=j;
		if(i!=min)
			swap(i,min);
	}
	return;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	selectionsort();
	for(i=1;i<=n-1;i++)
		printf("%d ",A[i]);
	printf("%d\n%d\n",A[n],sw);
	return 0;
}
