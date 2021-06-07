#include <stdio.h>
int main(int argc, char *argv[])
{
	int S[10000],T[500],n,q,i,j,k,count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&S[i]);
	scanf("%d",&q);
	for(i=0;i<q;i++)
	scanf("%d",&T[i]);
	//
	for(i=0;i<q;i++)
	{
		k=T[i];
		for(j=0;j<n;j++)
		if(S[j]==k)
		{
			count++;
			break;
		}
	}
	printf("%d\n",count);
	return 0;
}
