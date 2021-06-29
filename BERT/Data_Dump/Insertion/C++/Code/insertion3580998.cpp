#include <iostream>

using namespace std;

void printArr(int *arr,int n) {
	for (int i=0;i<n;i++) {
		if (i) {
			cout << " ";
		}
		cout << arr[i];
	}
	cout << endl;
}
void insertionSort(int *arr,int n) {
	printArr(arr,n);
	for (int i=1;i<n;i++) {
		int key = arr[i];
		int j = i-1;
		while (j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
		printArr(arr,n);
	}
}

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i=0;i<n;i++) {
		cin >> arr[i];
	}
	insertionSort(arr,n);
	delete[] arr;
	return 0;
}
