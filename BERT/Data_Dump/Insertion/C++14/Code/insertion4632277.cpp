#include <iostream>
#include <vector>
using namespace std;

void print_vector (const vector<int> &a) {
	for (size_t i = 0; i < a.size(); i++) {
		cout << a[i] << " \n"[i + 1 == a.size()];
	}
}

void insertion_sort (vector<int> &a, size_t n) {
	for (size_t i = 1; i < n; i++) {
		print_vector(a);
		int v = a[i];
		size_t j = i - 1;
		while (j >= 0 and a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
	}
}

int main() {
	size_t n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	insertion_sort(a, n);
	print_vector(a);
}
