#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

void output(int *data, int n) {
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			cout << " ";
		}
		cout << data[i];
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	int array[n];
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	output(array, n);
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j >= 1; j--) {
			if (array[j - 1] > array[j]) {
				swap(array[j - 1], array[j]);
			}
		}
		output(array, n);
	}
	return 0;
} 
