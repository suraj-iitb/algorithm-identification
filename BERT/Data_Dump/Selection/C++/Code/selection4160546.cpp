#include <iostream>
#include<vector>
#include<queue>
#include<string>
#include<list>
#include<algorithm>
using namespace std;
int c = 0;
void swap(int *x, int *y) {
	int temp;   
	temp = *x;
	*x = *y;
	*y = temp;
}
void selection_sort(int array[], int array_size) {
	int i, j, min_index;

	for (i = 0; i < array_size - 1; i++) {
		min_index = i;   
		for (j = i + 1; j < array_size; j++) {
			if (array[j] < array[min_index]) { min_index = j; }
		}
		if (min_index != i)
			++c;
		swap(&array[min_index], &array[i]);   
	}
}

int main(void) {
	int array[100];
	int i; int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> array[i];
	selection_sort(array, n);
	for (i = 0; i < n; i++) {
		if (i) {
			cout << " " << array[i];
		}
		else
			cout << array[i]
		; }
	cout << endl; cout << c << endl;
}
