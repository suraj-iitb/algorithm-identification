#include<iostream>

using namespace std;

int const MAX_N = 100;
int arr[MAX_N] = {};

void print(int arr[MAX_N], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i];
		if (i < n - 1) cout << " ";
	}
	cout << endl;
}

void insertionSort(int arr[MAX_N], int n) {
	for (int i = 1; i < n; i++) {
		print(arr, n);
		int v = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > v) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = v;
	}
}

void bubbleSort(int arr[MAX_N], int n) {
	bool flag = true;
	int count = 0;
	while (flag) {
		flag = false;
		for (int j = n - 1; j >= 1; j--) {
			if (arr[j] < arr[j - 1]) {
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
				flag = true;
				count++;
			}
		}
	}
	print(arr, n);
	cout << count << endl;
}

void selectionSort(int arr[MAX_N], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		int minj = i;
		for (int j = i; j < n; j++) {
			if (arr[j] < arr[minj]) {
				minj = j;
			}
		}
		if (i != minj) {
			int tmp = arr[i];
			arr[i] = arr[minj];
			arr[minj] = tmp;
			count++;
		}
	}
	print(arr, n);
	cout << count << endl;
}

int main() {
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	selectionSort(arr, n);

	return 0;
}

