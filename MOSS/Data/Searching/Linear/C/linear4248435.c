#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int S[10010],T[510],n,q;
int linearsearchS(int t)
{
	int i;
	for(i=1;i<=n;i++)
		if(S[i]==t)
			return 1;
	return 0;
}
int main()
{
	int C=0,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&S[i]);
	scanf("%d",&q);
	for(i=1;i<=q;i++)
		scanf("%d",&T[i]);
	for(i=1;i<=q;i++)
		C+=linearsearchS(T[i]);
	printf("%d\n",C);
	return 0;
}
