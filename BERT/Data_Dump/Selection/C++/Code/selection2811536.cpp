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
	
	for(int i=0; i<n; i++) {
		int mini = i;
		for(int j=i+1; j<n; j++) {
			if(a[j] < a[mini]) {
				mini = j;
			}
		}
		if(i != mini) {
			int tmp = a[i];
			a[i] = a[mini];
			a[mini] = tmp;
			cnt++;
		}
	}
	
	cout << a[0];
	for(int i=1; i<n; i++) {
		cout << " " << a[i];
	}
	cout << endl;
	cout << cnt << endl;
}

