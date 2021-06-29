#include<stdio.h>
int bubble(int A[100],int N)
  {
	int i,stock,j,c=0,flag=1;
	while(flag)
  {
		flag=0;
		for(i=N-1;i>0;i--)
  {
	if(A[i]<A[i-1])
  {
		stock=A[i];
		A[i]=A[i-1];
		A[i-1]=stock;
		flag=1;
		c++;
  }		
  }
  }
	return c;
  }
int main(void)
  {
	int i,n,x,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	x=bubble(a,n);
	for(i=0;i<n;i++)
  {
		printf("%d",a[i]);
		if(i<n-1){printf(" ");}
		else{printf("\n");}
  }
	printf("%d\n",x);
	return 0;
  }
