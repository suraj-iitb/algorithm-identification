#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int search(int s[], int n,int t)
{
	int c=0;
	s[n]=t;
	while(s[c]!=t)c++;
	return c!=n;
}

int main()
{
    int i,n,S[10000],q,T,count;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
	count = 0;
	for(i=0;i<q;i++)
	{
		scanf("%d",&T);
		if(search(S,n,T))
		{
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}
