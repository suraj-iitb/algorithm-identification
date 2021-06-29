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

int selectionSort(int a[], int len) {

	int count = 0;
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (a[min] > a[j]) min = j;
		}
		if (min != i) {
			swap(a[i], a[min]);
			count++;
		}
	}
	return count;
}

int main() {

	int n;
	cin >> n;
	
	int* r = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> r[i];
	}

	int count = selectionSort(r, n);
	printArr(r, n);
	cout << count << endl;

	delete[] r;
	return 0;
}

