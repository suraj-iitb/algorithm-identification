#include <iostream>

using namespace std;

#define MAX 500000
#define INF 1000000000
int L[MAX/2+2];
int R[MAX/2+2];
int cnt = 0;

void merge( int * ary, int left, int mid, int right ) {
	int n1 = mid - left;
	int n2 = right - mid;

	for ( int i = 0 ; i < n1 ; i++ ) {
		L[i] = ary[i+left];
	}

	for ( int i = 0 ; i < n2 ; i++ ) {
		R[i] = ary[i+mid];
	}
	L[n1] = INF;
	R[n2] = INF;

	int i = 0, j = 0;
	for ( int k = left ; k < right ; k++ ) {
		cnt++;
		if ( L[i] <= R[j] ) {
			ary[k] = L[i];
			i++;
		} else {
			ary[k] = R[j];
			j++;
		}
	}
}



void mergeSort( int * ary, int left, int right ) {
	if ( left+1 < right ) {
		int mid = (left+right)/2;
		mergeSort( ary, left, mid );
		mergeSort( ary, mid, right );
		merge( ary, left, mid, right );
	}
}

int main() {
	int n;
	int ary[MAX];
	cin >> n;

	for ( int i = 0 ; i < n ; i++ ) {
		cin >> ary[i];
	}
	mergeSort( ary, 0, n );

	for ( int i = 0 ; i < n ; i++ ) {
		if ( i != n-1 ) {
			cout << ary[i] << " ";
		} else {
			cout << ary[i] << endl;
		}
	}
	cout << cnt << endl;
	return 0;
}

