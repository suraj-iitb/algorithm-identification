#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> A(n);
	
	for (int i=0; i<n; i++){
		cin >> A[i];
		if (i != n-1){
			cout << A[i] << " ";
		} else {
			cout << A[i] << endl;
		}
	}

	for (int i=1; i<n; i++){
		int v=A[i];
		int j=i-1; 

		while(j>=0 && A[j] > v){
		A[j+1] = A[j];
		j--;
		A[j+1]=v;
		}

		for (int k=0; k<n;k++){
			if (k != n-1){
				cout << A[k] << " ";
			} else {
				cout << A[k] << endl;
			}
		}
	}
}
