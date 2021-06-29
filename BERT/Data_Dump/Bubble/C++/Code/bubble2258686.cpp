#include <iostream>

using namespace std;
int bubbleSort(int [], int);
int main() {
	int n;
	int A[100];
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> A[i];
	cout << bubbleSort(A, n) << endl;
	return 0;
}
int bubbleSort(int A[], int n){
	int sw = 0;
	int flag = 1;
	for(int i=0; flag; i++){
		flag = 0;
		for (int j=n-1; j>i; j--){
			if(A[j] < A[j-1]){
				int t = A[j];
				A[j] = A[j-1];
				A[j-1] = t;
				sw++;
				flag = 1;
			}
		}
	}
	for(int i=0; i<n-1; i++){
		cout << A[i] << ' ';
	}
	cout << A[n-1] << endl;
	return sw;
}
