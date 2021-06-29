#include <iostream>
#include <array>

#define MAX 100

using namespace std;


void printary( array< int, MAX > ary, int N )
{
	for ( int i = 0 ; i < N ; i++ ) {
		if ( i == N-1 ) {
			cout << ary[i] << endl;
		} else {
			cout << ary[i] << " ";
		}
	}
}

void insertionSort( array< int, MAX >ary, int N )
{
	int val, i, j;

	printary( ary, N );
	for ( i = 1 ; i < N ; i++ ) {
		val = ary[i];
		j = i - 1;
		while ( j >= 0 && ary[j] > val ) {
			ary[j+1] = ary[j];
			j--;
		}
		ary[j+1] = val;
		printary( ary, N );
	}
}

int main()
{
	int N, val, i;
	array< int, MAX > ary;

	cin >> N;
	for ( i = 0 ; i < N ; i++ ) {
		cin >> ary[i];
	}
	insertionSort( ary, N );

	return 0;
}

