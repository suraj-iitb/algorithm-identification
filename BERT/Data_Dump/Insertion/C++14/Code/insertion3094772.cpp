#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

void insertionSort(int A[], unsigned short int N);//ソート関数
void trace(int A[], unsigned short int N);//配列の要素を順番に出力

int main()
{
	unsigned short int N;
	int A[100] = {};

	cin >> N;

	for (int i = 0;i<N;i++)
	{
		scanf("%d", &A[i]);
	}
	trace(A, N);
	insertionSort(A, N);

	return 0;
}

void insertionSort(int A[], unsigned short int N)
{
	int v, j;
	for (int i = 1;i < N;i++)
	{
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		trace(A, N);
	}
}

void trace(int A[], unsigned short int N)
{
	cout << A[0];
	for (int i = 1;i < N;i++)
	{
		cout << " " << A[i];
	}
	cout << endl;
}
