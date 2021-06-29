#include <iostream>
using namespace std;

void println(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i + 1 < n) cout << " ";
	}
	cout << endl;
}

void iterationSort(int a[], int n) {
	println(a, n);
	for (int i = 1; i < n; i++) {
		int key = a[i];
		/*insert a[i] into the sorted sequence a[0]..a[i-1]*/
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
		println(a, n);
	}
}

int main() {
	int n;
	int a[100];
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	iterationSort(a, n);
	return 0;
}
