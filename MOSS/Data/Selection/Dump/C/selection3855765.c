#include <stdio.h>

static const int MAX = 100;

void swap(unsigned short *a, unsigned short *b ) {
	unsigned short temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

short selectionSort( unsigned short *p_dt, unsigned short n ) {
	short i, j, idx, sw = 0;

	for ( i = 0; i < n; i++ ) {
		idx = i;
		for ( j = i; j < n; j++ ) {
			if (p_dt[j] < p_dt[idx]) idx = j;
		}
		if ( idx != i ) {
			swap( &p_dt[i], &p_dt[idx] );
			sw++;
		}
	}
	return sw;
}

int main( void ) {
	short i, sw;
	unsigned short n, dt[MAX];

	scanf( "%d", &n );
	for ( i = 0; i < n; i++ ) scanf( "%d", &dt[i] );

	sw = selectionSort( dt, n );

	for ( i = 0; i < (n - 1); i++ ) printf( "%d ", dt[i] );
	printf( "%d\n%d\n", dt[i], sw );

	return 0;
}

