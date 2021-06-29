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
		int minj = i;
		for (int j = i; j <= n-1; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		if (i != minj) {
			int tmp = a[i];
			a[i] = a[minj];
			a[minj] = tmp;
			count++;
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
