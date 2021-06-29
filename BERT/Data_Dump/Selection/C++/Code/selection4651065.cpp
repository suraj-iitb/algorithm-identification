#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include<math.h>
#include <vector>
#include<bitset>
#include<map>
using namespace std;

int main() {
	int n, count = 0; cin >> n;
	int a[n]; for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++) {
		int minj = i;
		bool change = 0;
		for (int j = i; j < n; j++) {
			if (a[j] < a[minj]) {
				minj = j;
				change = 1;
			}
		}
		swap(a[i], a[minj]);
		if (change)count++;
	}
	for (int i = 0; i < n-1; i++)cout << a[i] << ' ';
	cout <<a[n-1]<< endl << count << endl;
}
