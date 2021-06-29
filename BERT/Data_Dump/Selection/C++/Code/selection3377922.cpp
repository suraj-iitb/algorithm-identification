#include <bits/stdc++.h>
using namespace std;

int selectionSort(int* A, int n){
	int cnt = 0;
	for(int i=0; i<n; i++){
		int minj = i;
		for(int j=i; j<n; j++){
			if(A[j] < A[minj]){
				minj = j;
			}
		}
		if(i != minj){
			cnt++;
			swap( A[i], A[minj] );
		}
	}
	return cnt;
}
int main(){
	int n;
	cin >> n;
	
	int A[100];
	for(int i=0; i<n; i++) cin >> A[i];
	
	int cnt = selectionSort(A, n);
	
	cout << A[0];
	for(int i=1; i<n; i++) cout << " " << A[i];
	cout << "\n" << cnt << endl;
	return 0;
}
