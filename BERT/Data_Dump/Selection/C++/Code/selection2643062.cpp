#include<iostream>
using namespace std;

int a[100];
int main() {
	int n,count=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n-1; i++) {
		int minj = 101,p;
		for (int j = i; j < n; j++) {
			if (a[j] < minj) {
				minj = a[j];
				p = j;
			}
		}
		if (a[i] > minj) {
			swap(a[i], a[p]);
			count++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i != n - 1)cout << " ";
		else cout << endl;
	}
	cout << count << endl;

	return 0;
}
