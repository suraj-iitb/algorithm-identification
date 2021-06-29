#include<stdio.h>
int N,Q,X[10000],i,t,r=0;
int main()
{
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d",X+i);
	for(scanf("%d",&Q);Q--;)
	{
		scanf("%d",&t);
		for(i=0;i<N;i++)
			if(X[i]==t)
			{
				r++;
				break;
			}
	}
	return !printf("%d\n",r);
}
