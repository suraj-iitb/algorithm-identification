#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<numeric>
#include<iomanip>
#include<queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int flag = 1;
	int count = 0;
	while (flag) {
		flag = 0;
		for (int j = n - 1; j > 0; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				count++;
				flag = 1;
			}

		}
	}
	for (int i = 0; i < n; i++) {
		cout<< a[i];
		if (i != n - 1) {
			cout << " ";
		}
		else {
			cout << endl;
		}
	}
	cout << count << endl;
	
}


