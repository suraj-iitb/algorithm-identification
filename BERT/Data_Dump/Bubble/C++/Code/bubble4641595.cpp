#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include<math.h>
using namespace std;

int main() {
	int n, i = 0, counter = 0; cin >> n;
	int a[n];
	for (int j = 0; j < n; j++)cin >> a[j];
	bool flag = 1;
	while (flag) {
		flag = 0;
		for (int j = n - 1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				flag = 1;
				counter++;
			}
		}
		i++;
	}
	for (int j = 0; j < n-1; j++)cout << a[j] << ' ';
	cout << a[n - 1] << endl << counter << endl;
}
