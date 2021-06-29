#include <iostream>
using namespace std;

int main() {
	int n, j, key;
	cin >> n;
	int *a = new int[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		key = a[i];
		j = i - 1;
		while(( j >= 0) && (a[j] > key)) {
			a[j+1] = a[j];
			a[j--] = key;
		}
		for (int j = 0; j < n-1; j++)
			cout << a[j] << ' ';
		cout << a[n-1] << endl; 
	}
	return 0;
}
