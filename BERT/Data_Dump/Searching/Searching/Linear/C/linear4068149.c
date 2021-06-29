#include <stdio.h>
int main ()
{
	int N,Q,A[10000],B[100000];
	int cnt=0;
	scanf("%d",&N);
	for(int i = 0;i<N;i++)	{
		scanf("%d",&A[i]);
	}
	scanf("%d",&Q);
	for(int i=0;i<Q;i++)	{
		scanf("%d",&B[i]);
		for(int j=0;j<N;j++)
		{
			if(A[j]==B[i]){
			 cnt++;
			 break;
			 }
		}
	}
	printf("%d\n",cnt);
	return 0;
}
