#include <iostream>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)
using namespace std;

void show(int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		if (i == n - 1)
			cout << arr[i] << endl;
		else
			cout << arr[i] << ' ';
	}
}

int bubbleSort(int arr[], int n)
{
	int cnt = 0, flag = 1, i = 0;
	while (flag) {
		flag = 0;
		for (int j = n - 1; j >= i + 1; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(int, arr[j], arr[j - 1]);
				cnt++;
				flag = 1;
			}
		}
		i++;
	}
	return cnt;
}

int main()
{
	int n, *arr, cnt;

	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cnt = bubbleSort(arr, n);
	show(arr, n);
	cout << cnt << endl;

	delete[] arr;
}
