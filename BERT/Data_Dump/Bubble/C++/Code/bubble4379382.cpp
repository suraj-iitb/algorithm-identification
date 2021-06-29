#include<iostream>
using namespace std;

template<typename T, typename U>
void swapArgs(T& a, U& b) {
	T t = a;
	a = (T)b;
	b = (U)t;
}

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int flag = 1;
	int count = 0;
	while (flag) {
		flag = 0;
		for (int i = n-1; i > 0; i--) {
			if (a[i] < a[i - 1]) {
				swapArgs(a[i], a[i - 1]);
				flag = 1;
				count++;
			}
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
