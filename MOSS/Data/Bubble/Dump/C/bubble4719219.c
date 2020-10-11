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
 	for(i=0;i<n-1;i++)
 		for(j=n-1;j>=i+1;j--)
 		{
 			if(a[j]<a[j-1])
 			{
 				swap(&a[j],&a[j-1]);
 				k++;
			 }
		 }
 	for(i=0;i<n;i++)
	{
		if(i>0)printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
	printf("%d\n",k);
 }
