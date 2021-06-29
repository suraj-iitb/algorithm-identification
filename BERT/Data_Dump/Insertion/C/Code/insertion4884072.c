#include <stdio.h>

void result(int a[],int n)//出力
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i>0)
		{
			printf(" ");
		}
		printf("%d",a[i]);
		
	}
	printf("\n");
}

void insertionSort(int a[],int n)//ソート
{
	int i,j,temp;
	result(a,n);
	
	for(i=1;i<=n-1;i++)
	{
		j=i;
		while(j>0&&a[j]<a[j-1])
		{
			temp=a[j-1];//交換
			a[j-1]=a[j];
			a[j]=temp;
			j--;
		}
		
		result(a,n);
	}
}
		


int main(void)
{
	int n,a[100],i;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	insertionSort(a,n);
	
	return 0;
	
	
}


