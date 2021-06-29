#include<iostream>
using namespace std;

int selectionSort(int A[], int N){
	int i, j, minj, sw=0;
	
	for(i = 0; i<N-1; i++){
		minj = i;
		for(j=i; j<N; j++){
			if(A[j] < A[minj]){
				minj = j;
			}
		}
		swap(A[i], A[minj]);
		if(i != minj) sw++;
	}
	//cout << sw <<endl;
	return sw;
}

int main(){
	int N, i, sw;
	int A[100];
	cin >> N;
	for(i=0; i<N; i++) cin >> A[i];

	sw = selectionSort(A, N);

	for(i=0; i<N;i++){
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << sw << endl;

	return 0;
}
