#include<iostream>
using namespace std;

int insertionSort(int A[], int N){
	for (int i=1; i<N; i++){
		int v,j;
		v = A[i];
		j = i-1;
		while (j>=0 && A[j]>v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;

		for (int j=0; j<N; j++){ 
			if (j) cout << " ";
			cout << A[j];
		}
		cout << endl;
	}
}

int main(){
	int A[100], N;
	cin >> N;
	for (int i=0; i<N; i++) cin >> A[i];
	
	for (int j=0; j<N; j++){ 
		if (j) cout << " ";
		cout << A[j];
	}
	cout << endl;
	insertionSort(A,N);
}
