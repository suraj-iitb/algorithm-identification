#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

void selectionSort(int A[], unsigned short int N);//ソート関数
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
	selectionSort(A, N);

	return 0;
}

void selectionSort(int A[], unsigned short int N)
{
	int minj, v;
	int c = 0;

	for (int i = 0;i < N;i++)
	{
		minj = i;

		for (int j = i; j<N ;j++)//未整列の領域（iからn-1）から最小値検索
		{
			if (A[j] < A[minj])
			{
				minj = j;
			}
		}
		v = A[i];
		A[i] = A[minj];
		A[minj] = v;
		if (i != minj)c = c + 1;
	}
	trace(A, N);
	cout << c << endl;
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
