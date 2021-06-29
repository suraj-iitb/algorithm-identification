#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> A(n), a(10001);
	for (int& i : A) {
		cin >> i;
		++a[i];
	}
	for (int i = 0, j = 0; i < n; ++i) {
		while (!a[j]) ++j;
		--a[j];
		A[i] = j;
	}
	for (int i = 0; i < n - 1; ++i) cout << A[i] << ' ';
	cout << A.back() << endl;
}
