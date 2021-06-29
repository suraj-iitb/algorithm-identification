#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int* p;
	p = new int[n];
	for (int i = 0;i < n;i++) {
		cin >> p[i];
	}
	for (int k = 0;k < n-1;k++)
		cout << p[k] << " ";
	cout << p[n - 1];
	cout << endl;
	int i, j, temp;
		for (i = 1;i < n;i++) {
			temp = p[i];
			for (j = i - 1;j >= 0 && p[j] > temp;j--) {
				p[j + 1] = p[j];
			}
			p[j + 1] = temp;
			for (int k = 0;k < n - 1;k++)
				cout << p[k] << " ";
			cout << p[n - 1];
			cout << endl;
	}
	return 0;
}
