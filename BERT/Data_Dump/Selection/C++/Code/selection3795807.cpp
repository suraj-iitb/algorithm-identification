#include <iostream>
#include <vector>

using namespace std;

void sort_and_print(vector<int>& a) {
	int nos = 0;
	int minj,size = a.size();
	for (int i = 0; i < size; ++i) {
		minj = i;
		for (int j = i; j < size; ++j) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		if (i != minj) {
			swap(a[i],a[minj]);
			++nos;
		}
	}
	for (int i = 0; i < size; ++i) {
		cout << a[i];
		if (i < size-1) {
			cout << " ";
		}
	}
	cout << endl;
	cout << nos << endl;
	return;
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

