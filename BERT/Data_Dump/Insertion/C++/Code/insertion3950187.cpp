#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[200005];
void insertionSort(int *arr, int n) {
	for (int i = 1; i <= n - 1; i++) {
		int v = arr[i];//记录当前元素的值
		int j = i - 1;
		while (j >= 0 && arr[j] > v) {//将当前元素之前的所有元素视为已排好的数组
			arr[j + 1] = arr[j];		//根据当前值的大小找到当前值的位置
			j--;
		}
		arr[j + 1] = v; //并将当前值插入数组中
		for (int i = 0; i < n - 1; i++)
			cout << arr[i] << " ";
		cout << arr[n - 1] << endl;
	}
}
int main()
{

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++)
		cout << a[i] << " ";
	cout << a[n - 1] << endl;
	insertionSort(a, n);
	return 0;
}
