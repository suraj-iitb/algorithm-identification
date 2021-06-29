#include<stdio.h>
int main(void)
{
	int N[10000]={0},i,j,k,m,n,q,c=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&q);
		N[i]=q;
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&q);
		for(j=0;j<n;j++)
		{
			if(N[j]==q){c++;break;}
		}
	}
	printf("%d\n",c);
	return 0;
}
