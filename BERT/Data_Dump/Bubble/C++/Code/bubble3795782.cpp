#include <iostream>
#include <vector>

using namespace std;

void sort_and_print(vector<int>& a) {
	int nos = 0;
	int size = a.size();
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = size-1; i > 0; --i) {
			if (a[i] < a[i-1]) {
				swap(a[i],a[i-1]);
				++nos;
				flag = true;
			}
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

