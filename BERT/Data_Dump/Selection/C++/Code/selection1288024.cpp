#include <iostream>
using namespace std;

int bubbleSort(int *array, int N) {
	int sortCount=0, min;
	for (int i=0; i<N-1; i++) {
		min = i;
		for (int j=i+1; j<N; j++) {
			if (array[min] > array[j]) {
				min = j;
			}
		}
		if (array[i] > array[min]) {
			int tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			sortCount++;
		}
		
	}
	return sortCount;
}

int main(int argc, const char * argv[]) {
	int N, array[100], sortCount=0;
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> array[i];
	}
	sortCount = bubbleSort(array, N);
	for (int i=0; i<N; i++) {
		cout << array[i];
		if (i == N-1) {
			cout << endl;
		} else {
			cout << " ";
		}
	}
	cout << sortCount << endl;

	return 0;
}
