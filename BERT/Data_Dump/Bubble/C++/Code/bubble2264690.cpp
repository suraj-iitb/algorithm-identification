#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
void BubbleSort(int arr[], int n, int& cnt);

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
	BubbleSort(arr, N, cnt);
	
	for (int i = 0; i != N - 1; ++i)
		printf("%d ", arr[i]);
	printf("%d\n", arr[N - 1]);
	printf("%d\n", cnt);
	//system("pause");
	return 0;
}

void BubbleSort(int arr[], int n, int& cnt)
{
	bool flag = true;;
	for (int i = 0; flag && i < n - 1; ++i)
	{
		flag = false;
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = true;
				swap(arr[j], arr[j + 1]);
				++cnt;
			}
		}
	}
}
