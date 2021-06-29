#include <iostream>
using namespace std;


int selectionSort(int A[], int n){
	int mini, count = 0;
	for( int i = 0; i < n - 1; i++) {
		mini = i;
		//search  a mini element position
		for ( int j = i; j < n; j++) {
			if (A[j] < A[mini]) {
				mini = j;
			}
		}
		swap(A[i], A[mini]);
		if(i != mini ) count++;
	}
	return count;
}

int main() {
	int n, A[100];
	cin >> n;

	for (int i = 0; i < n; i++) cin >> A[i];

	int c = selectionSort(A, n);
	for (int i = 0; i < n; i++) {
		if(i) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << c << endl;
	return 0;
}

