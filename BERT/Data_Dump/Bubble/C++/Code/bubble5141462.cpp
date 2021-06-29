#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> A(n);
	int num_swap = 0;
	
	for (int i=0; i<n; i++){
		cin >> A[i];
	}

	bool flag = 1;
	for (int i=0; flag; i++){
		flag = 0;
		for(int j=n-1; j >= i+1; j--){
			if(A[j] < A[j-1]){
				swap(A[j], A[j-1]);
				flag = 1;
				num_swap++;
			}
		}	
	}

	for (int k=0; k<n;k++){
		if (k != n-1){
			cout << A[k] << " ";
		} else {
			cout << A[k] << endl;
		}
	}
	cout << num_swap << endl;
}
