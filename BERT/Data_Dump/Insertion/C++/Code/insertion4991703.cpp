#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void insertionSort(vector<int> &A, int n){
	for(int k = 0; k < n; k++){
		if(k == n-1) cout << A[k] <<  endl;
		else cout << A[k] << " ";
	}
	for(int i = 1; i < n; i++){
		int num = A[i];
		for(int j = i-1; j > -1; j--){
			if(num>A[j]) break;
			else{
				A[j+1] = A[j];
				A[j] = num;
			}
		}
		for(int k = 0; k < n; k++){
			if(k == n-1) cout << A[k] << endl;
			else cout << A[k] << " ";
		}
	}
}
				




int main(){
	int n; cin >> n;
	
	vector<int> A(120);
	for(int i = 0; i < n; i++) cin >> A[i];
	insertionSort(A, n);
	return 0;

}

