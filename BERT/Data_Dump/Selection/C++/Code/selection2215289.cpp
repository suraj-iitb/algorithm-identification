#include "bits/stdc++.h"
using namespace std;

int sectionsort(int aa[], int n) {
	int sw = 0;
	int minv=1000000001;
	int minj=0;
	for (int i = 0; i<n; ++i) {
		minj=i;
		for (int j = i; j<n; j++) {
			if(aa[j]<aa[minj]){
				minj=j;
			}
		}
			swap(aa[i], aa[minj]);
			if(i!=minj)sw++;
		}
	return sw;
}

int main() {
	int n, sw;
	cin >> n;
	int aa[n];
	for (int i = 0; i < n; ++i) {
		cin >> aa[i];
	}
	sw = sectionsort(aa, n);
	for (int i = 0; i < n; ++i) {
		if(i)cout<<" ";
		cout<<aa[i];
	}
		cout<<endl;
		cout<<sw<<endl;
}
