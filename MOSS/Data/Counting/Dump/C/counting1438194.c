#include<stdio.h>
#define MN 2000005
int N,A[MN],B[MN],C[10005],i,j,k=-1;
void cs()
{
	for(i=0;i<N;i++)C[A[i]]++;
	for(i=1;i<=k;i++)
		C[i]+=C[i-1];
	for(j=N-1;j>=0;j--)
	{
		B[C[A[j]]-1]=A[j];
		C[A[j]]--;
	}
}
int main()
{
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		k=k>A[i]?k:A[i];
	}
	cs();
	for(i=0;i<N;i++)
		printf("%d%c",B[i],i==N-1?'\n':' ');
	return 0;
}
