#include <iostream>

using namespace std;
int selectSort(int [], int);
int main() {
	int n;
	int A[100];
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> A[i];
	cout << selectSort(A, n) << endl;
	return 0;
}
int selectSort(int A[], int n){
	int sw = 0;
	for(int i=0; i<n; i++){
		int minj = i;
		for(int j=i; j<n; j++){
			if(A[j] < A[minj]){
				minj = j;
			}
		}
		if(minj != i){
			int t = A[i];
			A[i] = A[minj];
			A[minj] = t;
			sw ++;
		}
	}
	for(int i=0; i<n-1; i++){
		cout << A[i] << ' ';
	}
	cout << A[n-1] << endl;
	return sw;
}
