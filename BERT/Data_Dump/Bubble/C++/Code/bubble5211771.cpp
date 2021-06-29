#include <iostream>
using namespace std;
int main(void){
	int n, cnt = 0, tmp;
	int a[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = n - 1; i > 0; i--) {
			if (a[i] < a[i - 1]) {
				tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
				cnt++;
				flag = true;
			}
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
