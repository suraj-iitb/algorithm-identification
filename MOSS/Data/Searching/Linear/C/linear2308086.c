#include <stdio.h>

int linearSearch(int *,int,int);

#define N 10000
#define Q 500
#define FOUND 1
#define NOT_FOUND 0

int main()
{
	int i,n,q,f,count=0,S[N],T[Q];

	scanf("%d",&n);
	for(i = 0;i < n;i++) scanf("%d",&S[i]);

	scanf("%d",&q);
	for(i = 0;i < q;i++) scanf("%d",&T[i]);

	for(i = 0;i < q;i++)
	{
		f = linearSearch(S,T[i],n);
		if(f == FOUND)count++;
	}

	printf("%d\n",count);

	return 0;

}

int linearSearch(int *A,int key,int n)
{
	int i=0;

	A[n] = key;

	while(A[i] != key)
	{
		i++;
	}

	if(i == n)return NOT_FOUND;
	else return FOUND;
}
