#include <iostream>

using namespace std;

#define MAX 2000000
#define K 10001
int A[MAX];
int B[MAX];
int C[K];

void CountingSort(int A[], int B[], int n)
{
	for (int i = 0; i < K; ++i) C[i] = 0;

	// 在C[i]中记录A[i]元素出现的次数
	for (int i = 0; i < n; ++i) ++C[A[i]];

	// 在C[i]中记录小于等于A[i]元素出现的次数
	for (int i = 1; i < K; ++i) C[i] = C[i] + C[i - 1];

	int index = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		index = C[A[i]] - 1;
		B[index] = A[i];
		--C[A[i]];
	}
}

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
		B[i] = A[i];
	}

	CountingSort(A, B, n);

	for (int i = 0; i < n; ++i)
		cout << B[i] << (i != n - 1 ? " " : "\n");
}
