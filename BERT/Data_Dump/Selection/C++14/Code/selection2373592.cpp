#include<iostream>
using namespace std;

int selectionSort(int arr[], int size) {
	int idxMin;
	int sw = 0;
	for (int i = 0; i < size; i++) {
		idxMin = i;
		for (int j = i; j < size; j++) {
			if (arr[j] < arr[idxMin]){
				idxMin = j;
			}
		}
		if (i != idxMin) {
			swap(arr[i], arr[idxMin]);
			sw++;
		}
	}
	return sw;
}

int main() {
	int size, sw;
	cin >> size;

	int* arr = new int[size];
	for (int i = 0; i < size; i++)cin >> arr[i];

	sw = selectionSort(arr, size);
	for (int i = 0; i < size; i++) {
		if (i) cout << ' ';
		cout << arr[i];
	}
	cout << endl << sw << endl;
}
