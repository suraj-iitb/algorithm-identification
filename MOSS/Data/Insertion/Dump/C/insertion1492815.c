#include<stdio.h>
int insert(int A[101],int n)
{
	int i,j,k,v;
	for(i=1;i<n;i++)
	{
		for(k=0;k<n;k++)
		{
			printf("%d",A[k]);
			if(k!=n-1){printf(" ");}
			else{printf("\n");}
		}
		v=A[i];
		j=i-1;
		while(j>=0 && A[j]>v)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
	}
	for(k=0;k<n;k++)
	{
		printf("%d",A[k]);
		if(k!=n-1){printf(" ");}
		else{printf("\n");}
	}
	return 0;
}
int main(void)
{
	int n,i,A[101];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{scanf("%d",&A[i]);}
	insert(A,n);

	return 0;
}
