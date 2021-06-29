#include <iostream>
using namespace std;

#define FOR(i,n,m) for(int i=n; i<m; i++)

void insertionsort(int* A, int N);

int main () {
	int N;
	cin >> N;
	int A[N];
	FOR(i,0,N) cin >> A[i];
	FOR(i,0,N-1) cout <<  A[i] << " ";
	cout << A[N-1] <<  endl;
	insertionsort(A,N);
	
	
	return 0;
}

void insertionsort(int* A, int N) {
	int v;
	int j;
	FOR(i,1,N) {
		v = A[i];
		j = i-1;
		while(j>=0 && A[j] > v) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		FOR(k,0,N-1) cout << A[k] << " ";
		cout << A[N-1] << endl;
	}
	
	
}
