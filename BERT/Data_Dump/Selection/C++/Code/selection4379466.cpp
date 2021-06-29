#include<iostream>
using namespace std;

template<typename T>
void swapArgs(T& a, T& b) {
	T t = a;
	a = b;
	b = t;
}

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		int minj = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		if (i != minj) {
			swapArgs(a[i], a[minj]);
			count++;
		}
	}
	cout << a[0];
	for (int i = 1; i < n; i++) {
		cout << " " << a[i];
	}
	cout << endl << count << endl;
	delete[] a;
	return 0;
}
