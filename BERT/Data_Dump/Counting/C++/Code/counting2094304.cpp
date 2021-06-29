#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX_N = 2000000;

int main()
{
	int n,A[MAX_N] = {0},B[MAX_N] = {0},C[10000] ={0},max;

	scanf("%d", &n);

	max = 0;

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
		if (max < A[i])
		{
			max = A[i];
		}
	}

	

	for(int i = 0; i < n; i++)
	{
		C[A[i]]++;
	}

	for(int i = 1; i <= max; i++)
	{
		C[i] += C[i-1];
	}
	
	for(int i = n-1; i >= 0; i--)
	{
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}


	for(int i = 1; i <= n; i++)
	{
		if (i == n)
		{
			printf("%d\n", B[i]);
		}else
		{
			printf("%d ", B[i]);
		}
	}

	return 0;
}
	
