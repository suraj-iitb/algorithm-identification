//ALDS1_6_A Sort II - Counting Sort
#include <cstdio>
using namespace std;
#define MAX 2000001
#define VMAX 10000

void dump(int *A, int s,int n)
{
	for (int i = s; i < n; i++)
	{
		if (i != s)
			printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}

int main(void)
{

	int n, k = 0;
	scanf("%d", &n);
	int *A = new int[n + 2];
	int *B = new int[n + 2];
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &A[i+1]);
		if (A[i+1] > k)
		{
			k = A[i+1];
		}
	}
	//dump(A,1, n+1);
	int *C = new int[k + 1];
	//初期化
	for (int i = 0; i < k+1; i++)
	{
		C[i] = 0;
	}
	//dump(C,0, k+1);
	//要素の数を数える
	for (int i = 0; i < n; i++)
	{
		C[A[i+1]]++;
	}
	//dump(C,0, k+1);
	//要素の累積数
	for (int i = 1; i < k+1; ++i)
	{
		C[i] = C[i] + C[i - 1];
	}
	//dump(C,0, k+1);
	for (int j = n; j >= 1; j--)
	{
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}
	dump(B,1, n+1);
	delete[] A;
	delete[] B;
	delete[] C;
	return 0;
}

