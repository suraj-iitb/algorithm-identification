#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int a[100], n,sum=0;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = n-1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]); sum++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i != n - 1)cout << " ";
	}
	cout <<endl<< sum << endl;
}
