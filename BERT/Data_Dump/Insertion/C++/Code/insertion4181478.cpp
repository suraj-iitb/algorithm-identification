#include <iostream>

using namespace std;

void printArr(int a[], int len) {


	for (int i = 0; i < len; i++)
	{
		if (i == 0) cout << a[0];
		else cout << " " << a[i];
	}
	cout << endl;
}

//5 2 4 6 1 3

void insertionSort(int a[], int len) {
	printArr(a, len);
	for (int i = 1; i < len; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (a[j] > key && j >= 0) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
		printArr(a, len);
	}
}




int main() {

	int n;
	cin >> n;

	int arr[100] = { 0 };

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	insertionSort(arr, n);
//	printArr(arr, n);


	return 0;
}

