#include <stdio.h>

int C[10001],D[10001];

int main()
{
	int n, i, place=0;

	scanf("%d",&n);

	int A[n],B[n];

	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		C[A[i]]++;
	}

	for(i=0;i<10001;i++)
	{
		place+=C[i];
		D[i]=place-1;
	}
	for(i=0;i<n;i++)
	{
		B[D[A[i]]]=A[i];
		D[A[i]]--;
	}

	for(i=0;i<n;i++)
	{
		if(i>0)printf(" ");
		printf("%d",B[i]);
	}
	printf("\n");
	

	return 0;
}
