#include <stdio.h>
void trace(int a[],int N)
{
	int i;
	for(i=0;i<N;i++)
	{
		if(i>0) printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
}
void insertionSort(int a[],int N)
{
	int i,j,v;
	for(i=1;i<=N-1;i++)
	{
		v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		trace(a,N);
	}
}
int main()
{
	int i,j,N;
	int a[100];
	scanf("%d",&N);
	for(i=0;i<N;i++) scanf("%d",&a[i]);
	trace(a,N);
	insertionSort(a,N);
	return 0;
}
