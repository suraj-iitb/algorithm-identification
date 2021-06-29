#include <iostream>
#include <algorithm>

using namespace std;

void show(int arr[], int n) {
	for (int i = 0; i < n - 1; i++)
		cout << arr[i] << " ";
	cout << arr[n - 1] << endl;
}

int bubbleSort(int arr[], int n) {
	bool f = true;
	int temp;
	int resCnt = 0;
	while (f) {
		f = false;
		for (int i = n - 1; i >= 1; i--)
			if (arr[i] < arr[i - 1]) {
				temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
				f = true;
				resCnt++;
			}
	}
	return resCnt;
}

int main() {
	int arr[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int resCnt = bubbleSort(arr, n);
	show(arr, n);
	cout << resCnt << endl;

	return 0;
}
