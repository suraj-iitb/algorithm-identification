#include <iostream>
using namespace std;

// flag?????¨????????????????????????
int bubbleSort(int arr[], int n) {
	int count = 0;
	bool flag = 1;
	for (int i = 0; flag; i++) {
		flag = 0;
		for (int j = n - 1; j >= i + 1; j--) {
			if (arr[j] < arr[j -1]) {
				// ??£??\????´????????????????
				swap(arr[j], arr[j - 1]);
				flag = 1;
				count++;
			}
		}
	}
	return count;
}

int main() {
	int arr[100], n, count;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	count = bubbleSort(arr, n);

	for (int i = 0; i < n; i++) {
		if (i) {
			cout << " ";
		}
		cout << arr[i];
	}
	cout << endl;
	cout << count << endl;

	return 0;
}
