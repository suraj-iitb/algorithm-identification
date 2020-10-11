#include <stdio.h>

/*関数*/
//配列を初期化する
int InitArray(void);
//挿入ソート
void InsertionSort(int* a, int n);
//結果を表示する
void print(int a[], int n);

//データの数の最大値
#define nMax 100

int main(void)
{
	int a[nMax];	//データを入れる配列
	int n;			//データの個数
	int i;

	//データの数を入力する
	scanf("%d", &n);

	//配列にデータを入力する
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	//挿入ソートを行う
	InsertionSort(a, n);

	return 0;
}

//配列を初期化する
int InitArray(void)
{
	int a[nMax];
	int i;

	for (i = 0; i < nMax; i++)
	{
		a[i] = 0;
	}
}

//挿入ソート
void InsertionSort(int* a, int n)
{
	int i;
	int j;
	int v;

	print(a, n);

	for (i = 1; i < n; i++)
	{
		v = a[i];
		j = i - 1;
		while ((j >= 0) && (a[j] > v))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		print(a, n);
	}
}

//結果を表示する
void print(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (i + 1 < n)
		{
			printf("%d ", a[i]);
		}
		else
		{
			printf("%d\n", a[i]);
		}
	}
}
