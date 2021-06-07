#include<stdio.h>

#define MAX_s 10000
#define MAX_t 500

int linearSearch(int A[],int key,int n)
{	
	int i = 0;
	A[n] = key;
	
	/*while (A[i] !=key)
	{
		i++;
		if(i==n){
			return 0;
		}
		return 1;
	}*/
	for(i=0;i<=n-1;i++)
	{
		if(A[i]==key){
			return 1;
		}
	}
	
	return 0;
}

int main(void)
{
	int i,j,k,n,q;
	int c=0;
	int S[MAX_s];
	int T[MAX_t];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&S[i]);
	}
	
	scanf("%d",&q);
	
	for(j=0;j<q;j++)
	{
		scanf("%d",&T[j]);
	}
	
	for(k=0;k<q;k++)
	{
		c=c+linearSearch(S,T[k],n);
	}
	
	printf("%d\n",c);
	
	return 0;
}
