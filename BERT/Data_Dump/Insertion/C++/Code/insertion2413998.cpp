#include <bits/stdc++.h>
using namespace std;

void insertionSert(int *A, int N){
	for(int i=1; i<N; i++){
		int tmp = A[i];
		for(int j=i-1; j>=0; j--){
			if(A[j]>tmp){
				A[j+1] = A[j];
				A[j] = tmp;
			}
		}
		for(int k=0;k<N;k++)
			cout << A[k] << ((k==N-1)?"":" ");
		cout << endl;
	}
}

int main(){
	int N; cin >> N;
	int A[N];
	for(int i=0;i<N;i++){
		cin >> A[i];
		cout << A[i] << ((i==N-1)?"":" ");
	}
	cout << endl;
	insertionSert(A,N);
	return 0;
}
