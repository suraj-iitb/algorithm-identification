#include<stdio.h>
int selection(int A[100],int N)
{
	int i,j,d,minj,stock,c=0;
	for(i=0;i<N;i++)
	{
		minj=i;
		for(d=0,j=i;j<N;j++)
		{
			if(A[j]<A[minj]){minj=j;d=1;}
		}
		stock=A[i];
		A[i]=A[minj];
		A[minj]=stock;
		if(d)c++;
	}
	return c;
}
int main(void)
  {
	int i,n,x,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	x=selection(a,n);
	for(i=0;i<n;i++)
  {
		printf("%d",a[i]);
		if(i<n-1){printf(" ");}
		else{printf("\n");}
  }
	printf("%d\n",x);
	return 0;
  }
