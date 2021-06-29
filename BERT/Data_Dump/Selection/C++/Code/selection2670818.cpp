#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

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

void selectSort(int A[], int n)
{
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		int mini = i;
		for(int j = i; j < n; j++)
		{
			if(A[j] < A[mini])
			{
				mini = j;
			}
		}
		swap(A[i], A[mini]);
		if (i != mini) {
			cnt++;
		}
	}
	trace(A, n);
	printf("%d\n", cnt);
}


int main(int argc, char *argv[]) {
	int N, A[101];
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	selectSort(A, N);
	return 0;
}
