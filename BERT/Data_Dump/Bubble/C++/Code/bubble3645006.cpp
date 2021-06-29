#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, a[100], num = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = n - 1; j > 0; j--) {
			if(a[j - 1] > a[j]) {
				swap(a[j - 1], a[j]);
				num++;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		cout << a[i] << (i == n - 1 ? "\n" : " ");
	}
	cout << num << endl;
	return 0;
}
