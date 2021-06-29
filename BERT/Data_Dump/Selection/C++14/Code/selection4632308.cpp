#include <iostream>
#include <vector>

using namespace std;

int number = 0;

void selection_sort (vector<int> &a, size_t n) {
	for (int i = 0; i < n; i++) {
		int min_j = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[min_j]) min_j = j;
		}
		if (i != min_j) {
			swap(a[i], a[min_j]);
			number++;
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
	
	selection_sort(a, n);
	
	for (size_t i = 0; i < n; i++) {
		cout << a[i] << " \n"[i + 1 == n];
	}
	
	cout << number << '\n';
	
	return 0;
}
