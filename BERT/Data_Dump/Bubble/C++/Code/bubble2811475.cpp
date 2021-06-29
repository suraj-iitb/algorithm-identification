/*
 * ITP1_6_B.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: 13743
 */

#include<iostream>
#include<cmath>

using namespace std;


int main() {
	int n;
	int a[100];
	int cnt = 0;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	int last = n;
	for(int i=0; i<last; i++) {
		for(int j=n-1; j>i; j--) {
			if(a[j] < a[j-1]) {
				int tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
				cnt++;
			}
		}
	}
	cout << a[0];
	for(int i=1; i<n; i++) {
		cout << " " << a[i];
	}
	cout << endl;
	cout << cnt << endl;
}

