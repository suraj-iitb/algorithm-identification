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
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		int minj = i;
		for (int j= i; j < n; j++) {
			if (a[j] < a[minj]) {
				minj = j;
				
			}
		}
		swap(a[i], a[minj]);
		if(i!=minj)count++;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i != n - 1) {
			cout << " ";
		}
		else {
			cout << endl;
		}
	}
	cout << count << endl;
}


