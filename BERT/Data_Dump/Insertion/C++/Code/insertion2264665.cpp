#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
void InsertSort(int arr[], int n);
void Print(int arr[], int n, bool flag = true)
{
	for (int i = 0; i != n - 1; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("%d", arr[n - 1]);
	if (flag)
		printf("\n");
}
int main(void)
{
	int N;
	int arr[105];
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	cin >> N;
	for (int i = 0; i != N; ++i)
		scanf("%d", &arr[i]);
	InsertSort(arr, N);
	//system("pause");
	return 0;
}

void InsertSort(int arr[], int n)
{
	
	for (int i = 1; i < n; ++i)
	{
		Print(arr, n);
		int j = i - 1, elem = arr[i];
		while (arr[j] > elem && j >= 0)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = elem;
	}
	Print(arr, n);
}
