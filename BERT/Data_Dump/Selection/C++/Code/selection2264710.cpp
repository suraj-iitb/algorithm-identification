#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
void SelectSort(int arr[], int n, int& cnt);

int main(void)
{
	int N;
	int arr[105];
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	cin >> N;
	int cnt = 0;
	for (int i = 0; i != N; ++i)
		scanf("%d", &arr[i]);
	SelectSort(arr, N, cnt);
	
	for (int i = 0; i != N - 1; ++i)
		printf("%d ", arr[i]);
	printf("%d\n", arr[N - 1]);
	printf("%d\n", cnt);
	//system("pause");
	return 0;
}

void SelectSort(int arr[], int n, int& cnt)
{
	int min_idx, min_value;
	for (int i = 0; i < n - 1; ++i)
	{
		min_idx = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[min_idx] > arr[j])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			swap(arr[i], arr[min_idx]);
			++cnt;
		}
	}
}
