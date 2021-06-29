#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX 2000001
#define VMAX 10000


int main()
{
	unsigned short *A,*B;

	int C[VMAX+1];
	for (int i = 0; i < VMAX+1; ++i)
	{
		C[i] = 0;
	}
	int n;
	scanf("%d",&n);

	A = (unsigned short *)malloc(sizeof(short)*n+1);
	B = (unsigned short *)malloc(sizeof(short)*n+1);

	for (int i = 0; i < n; ++i)
	{
		scanf("%hu",&A[i+1]);
		C[A[i+1]]++;
	}

	for (int i = 1; i <= VMAX;++i)
	{
		C[i] = C[i] + C[i-1];
	}

	for (int i = n; i > 0 ; --i)
	{
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (i > 1)
		{
			printf(" ");
		}
		printf("%hu",B[i]);
	}
	printf("\n");


	return 0;
}