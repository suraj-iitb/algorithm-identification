#include <stdio.h>
#define N 200000

void swap(int *x, int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
 } 
 
 int main()
 {
 	int i,j,k,n,a[N];
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	scanf("%d",&a[i]);
 	int min;
 	for(i=0;i<=n-1;i++)
 	{ 
 		min=i; 
 		for(j=i;j<=n-1;j++)
 		{
 			if(a[j]<a[min])
 				min=j;
		 }
		 swap(&a[i], &a[min]);
		 if(i!=min)
		 k++;
	} 
 	for(i=0;i<n;i++)
	{
		if(i>0)printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
	printf("%d\n",k);
 }
