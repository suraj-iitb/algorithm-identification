#include <iostream>
#include <array>

#define MAX 100

using namespace std;

void selectionSort( array< int, MAX> ary, int N )
{
	int i, j, minj, tmp, exchange = 0;
	int flag = 0;

	for ( i = 0 ; i < N ; i++ ) {
		minj = i;
		flag = 0;
		for ( j = i ; j < N ; j++ ) {
			if ( ary[minj] > ary[j] ) {
				minj = j;
				flag = 1;
			}
		}

		if ( flag == 1 ) { exchange++; }
		tmp = ary[minj];
		ary[minj] = ary[i];
		ary[i] = tmp;
	}
	

	for ( i = 0 ; i < N ; i++ ) {
		if ( i == N-1 ) {
			cout << ary[i] << endl;
		} else {
			cout << ary[i] << " ";
		}
	}
	cout << exchange << endl;
}	

int main()
{
	int N;
	array< int, MAX > ary;

	cin >> N;
	for ( int i = 0 ; i < N ; i++ ) {
		cin >> ary[i];
	}
	selectionSort( ary, N );
	return 0;
}

