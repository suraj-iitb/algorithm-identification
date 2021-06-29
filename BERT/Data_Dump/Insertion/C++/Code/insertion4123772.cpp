#include <iostream>
using namespace std;

#define SIZE 100

void insertionSort(int n, int* A){
	int v, k;
	for(int i = 1; i < n; ++i){
		v = A[i];
		k = i - 1;
		while(k >= 0 && A[k] > v) {
			A[k + 1] = A[k];
			--k;
		}
		A[k + 1] = v;
		
		for(int j = 0; j < n; ++j){
			if(j != n - 1)
				cout << A[j] << ' ';
			else
				cout << A[j] << endl;
		}
	}
}

int main(void){
	int n;
	int A[SIZE];
	
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> A[i];
	
	for(int i = 0; i < n; ++i) {
		if(i != n - 1)
			cout << A[i] << ' ';
		else
			cout << A[i] << endl;
	}
	
	insertionSort(n, A);
	
	return 0;
}
