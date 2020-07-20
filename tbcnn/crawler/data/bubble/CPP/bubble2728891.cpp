#include <iostream>
#include <cstdio>
using namespace std;

void printArray(int* array, int length) {
	for (int i = 0; i < length; i++) {
		cout << array[i];
		if (i != length - 1)  cout << " ";
		else cout << endl;
	}
}

void bubbleSort(int* array, int length) {
	int swap = 0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length - 1; j++) {
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap++;
			}
		}
	}
	printArray(array, length);
	cout << swap << endl;
}

int main()
{
	int loop;
	int array[100] = {};

	cin >> loop;
	for (int i = 0; i < loop; i++) cin >> array[i];

	bubbleSort(array, loop);

	return 0;
}

