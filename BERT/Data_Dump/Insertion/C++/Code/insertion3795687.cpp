#include <iostream>
#include <vector>

using namespace std;

void sort_and_print(vector<int>& a) {
	int val,ind;
	int size = a.size();
	for (int j = 0; j < size; ++j) {
		cout << a[j];
		if (j < size-1) {
			cout << " ";
		}
	}
	cout << endl;
	for (int i = 1; i < size; ++i) {
		val = a[i];
		ind = i-1;
		while (ind >= 0 && a[ind] > val) {
			a[ind+1] = a[ind];
			--ind;
		}
		a[ind+1] = val;	
		for (int j = 0; j < size; ++j) {
			cout << a[j];
			if (j < size-1) {
				cout << " ";
			}
		}
		cout << endl;
	}
}

int main(void) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort_and_print(a);
	return 0;
}

