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

	for (int i=0; i<=n-1; i++){
		int min_num = i;
		for(int j=i; j < n; j++){
			if(A[j] < A[min_num]){
				min_num = j;
			}
		}
		if(min_num != i){
		swap(A[i], A[min_num]);
		num_swap++;
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
