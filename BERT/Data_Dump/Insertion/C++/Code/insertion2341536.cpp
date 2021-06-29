//============================================================================
// Name        : ALDS1_1_A.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a;
	int i,j,n,key;
	cin >> n;
	a.resize(n);
	for(i=0; i<n; ++i) {
		cin >> a[i];
	}
	for(i=0; i<n; ++i) {
		key=a[i];
		for(j=i-1;j>=0 && a[j]>key; --j) {
			a[j+1]=a[j];
		}
		a[j+1]=key;
		for(int i=0; i<(int)a.size()-1; ++i) {
			cout << a[i] << " ";;
		}
		cout << a[(size_t)a.size()-1] << endl;
	}
	return 0;
}
