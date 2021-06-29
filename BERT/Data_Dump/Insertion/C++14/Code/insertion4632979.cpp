#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& a) {
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		if (!i) cout << a[0];
		else cout << " " << a[i];
	}
	cout << endl;
	for (int i = 1; i < n; ++i) {
		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		for (int j = 0; j < n; j++) {
			if (!j) cout << a[0];
			else cout << " " << a[j];
		}
		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	insertionSort(a);

	return 0; 
}
