#include<stdio.h>

int linearSearch(int T[],int S[],int n,int j)
{
	int i = 0;
    S[n] = T[j];
	
	while(S[i]!=T[j])
	{
		i++;
	}
	
	if(i==n)
	{
      return -1;
	}
	
	return i;
}

int main(void)
{
	int n,S[20000],q,T[20000],C=0,i,j;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&S[i]);
	}
	
	scanf("%d",&q);
	
	for(j=0;j<q;j++)
	{
		scanf("%d",&T[j]);
		
		if(linearSearch(T,S,n,j)!= -1){C++;}
	}
	
	printf("%d\n",C);
	
	return 0;
}


