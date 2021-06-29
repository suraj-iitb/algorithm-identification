#include <iostream>
using namespace std;
int main(void){
	int n, cnt = 0;
	int a[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		int minj = i;
		for (int j = i; j < n;j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		if (minj != i) {
			int tmp = a[i];
			a[i] = a[minj];
			a[minj] = tmp;
			cnt++;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i == n - 1) {
			cout << endl;
		}
		else {
			cout << " ";
		}
	}
	cout << cnt << endl;
}
