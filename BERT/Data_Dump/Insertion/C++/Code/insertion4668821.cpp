#include <iostream>
using namespace std;

void p_list(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (i != 0) cout << " ";
		cout << a[i];
	}
	cout << "\n";
}

void insertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		p_list(a, n);
	}
}

int main() {
	int num;
	cin >> num;
	int list[100];
	for (int i = 0; i < num; i++) {
		cin >> list[i];
	}
	p_list(list, num);
	insertionSort(list, num);

	return 0;
}
