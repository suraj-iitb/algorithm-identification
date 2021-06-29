#include <iostream>
#include <vector>

using namespace std;

int inversion = 0;

void bubble_sort (vector<int> &a, size_t n) {
	bool flag = true;
	while (flag) {
		flag = false;
		for (size_t j = n; j --> 1;) {
			if (a[j] < a[j - 1]) {
				inversion++;
				swap(a[j], a[j - 1]);
				flag = true;
			}
		}
	}
}

int main() {
	size_t n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	bubble_sort(a, n);
	
	for (size_t i = 0; i < n; i++) {
		cout << a[i] << " \n"[i + 1 == n];
	}
	
	cout << inversion << '\n';
	
	return 0;
}
