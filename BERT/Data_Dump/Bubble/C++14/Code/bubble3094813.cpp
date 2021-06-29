#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

void bubbleSort(int A[], unsigned short int N);//ソート関数
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
	bubbleSort(A, N);

	return 0;
}

void bubbleSort(int A[], unsigned short int N)
{
	bool flag = 1;
	int v, c;
	c = 0;

	while (flag)
	{
		flag = 0;
		for (int j = N - 1;j > 0;j--)//数列最後尾から順に逆順要素の有無確認
		{
			if (A[j] < A[j - 1])//逆順要素入れ替え
			{
				v= A[j];
				A[j] = A[j-1];
				A[j - 1] = v;
				c = c + 1;
				flag = 1;//逆順要素入れ替えした場合、flag=1にする。
			}
		}
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
