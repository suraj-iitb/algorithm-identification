#include <stdio.h>
#include <iostream>
#include <utility>
using namespace std;

int sort(int a[], int n);

int main(void)
{	
	int n, a[100];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	int num = sort(a, n);
	
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i < n - 1) cout << " ";
		else cout << endl;
	}
	cout << num << endl;
	
	return 0;
}

int sort(int a[], int n)
{
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (a[j] < a[j-1]) {
				swap(a[j], a[j-1]);
				cnt++;
			}
		}
	}
	
	return cnt;
}
