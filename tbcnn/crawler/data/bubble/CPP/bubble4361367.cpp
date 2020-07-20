#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	bool flag = true;
	int count = 0;
	while (flag) {
		flag = false;
		for (int i = 0;i < n- 1;i++) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				count++;
				flag = true;
			}
		}
	}
	for (int i = 0;i < n - 1;i++) {
		cout << a[i] << " ";
	}
	cout << a[n - 1] << endl;
	cout << count << endl;
}
