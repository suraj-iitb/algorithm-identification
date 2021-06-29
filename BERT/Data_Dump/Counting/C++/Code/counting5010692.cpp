#include <bits/stdc++.h>
using namespace std;

#define k 10000


void CountingSort(int A[], int B[], int C[], int n) {
	for (int i = 0; i <= k; i++){
		C[i] = 0;
	}
	
	for (int j = 0; j < n; j++){
		C[A[j]]++;
	}	
	
	for (int i = 1; i <= k; i++){
		C[i] = C[i] + C[i-1];
	}
	
	for (int j = n -1; j >=0; j--) {
		B[C[A[j]]-1] = A[j];
		C[A[j]]--;
	}
	
}

int main(){
	int n;
	cin >> n;
	
	int A[n], B[n], C[k+1];
	
	for (int i = 0; i < n; i++) cin >> A[i];
	
	CountingSort(A, B, C, n);
	
	for (int i = 0; i< n; i++) {
		if (i == n -1) cout << B[i] << endl;
		else cout << B[i] << " ";
	}
	
	return 0;
}
