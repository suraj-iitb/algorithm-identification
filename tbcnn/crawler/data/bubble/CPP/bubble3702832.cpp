#include <iostream>
using namespace std;

int main() {
	int n, a[100];
	cin >> n;
	for (int i = 0; i <= n-1; i++) {
		cin >> a[i];
	}
	
	int count = 0;
	for (int i = 0; i <= n-1; i++) {
		int flag = 1;
		while (flag) {
			flag = 0;
			for (int j = n-1; j >= 1; j--) {
				if (a[j] < a[j-1]) {
					int tmp = a[j];
					a[j] = a[j-1];
					a[j-1] = tmp;
					flag = 1;
					count++;
				}
			}
		}
	}
	
	for (int i = 0; i <= n-1; i++) {
		cout << a[i];
		if (i < n-1) {
			cout << " ";
		} else {
			cout << endl;
		}
	}
	cout << count << endl;
	return 0;
}
