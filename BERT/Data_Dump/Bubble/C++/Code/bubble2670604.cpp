#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N, A[101];

void trace(int A[], int len)
{
	for(int i = 0; i < len; i++)
	{
		printf("%d", A[i]);
		if(i < len-1)
		{
			printf(" ");
		}
	}
	printf("\n");
}


void BubbleSort(int A[], int n)
{
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		for (int j = n-1; j >= i+1; j--) {
			if(A[j] < A[j-1])
			{
				swap(A[j], A[j-1]);
				cnt++;
			}
		}
	}
	trace(A, n);
	printf("%d\n", cnt);
	return;
}

int main(int argc, char *argv[]) {
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	BubbleSort(A, N);
	return 0;
}
