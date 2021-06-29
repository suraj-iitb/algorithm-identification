#include <iostream>
#include <algorithm>
using namespace std;
const static int MAX = 100;

void printArray(int* array, int loop) {
	for (int i = 0; i < loop; i++) {
		if(i != loop - 1) cout << array[i] << " ";
		else cout << array[i] << endl;
	}
}

void insertSort(int* array, int loop) {
	int v, j;

	printArray(array, loop);

	for (int i = 1; i < loop; i++) {
		v = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > v) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = v;
		printArray(array, loop);
	}
	//printArray(array, loop);
}

int main()
{
	int loop = 0;
	int a[MAX];

	cin >> loop;
	for (int i = 0; i < loop; i++) cin >> a[i];

	insertSort(a, loop);

	return 0;
}
