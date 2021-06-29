#include <stdio.h>

static const int MAX = 100;

void trace( unsigned short *p_dt, unsigned short arg_n ) {
	short i;
	for( i = 0; i < (arg_n - 1); i++ ) printf( "%d ", p_dt[i] );
	printf( "%d\n", p_dt[i] );
}

void insertionSort( unsigned short *p_dt, unsigned short arg_n ) {
	short i, j, v;
	trace( p_dt, arg_n );
	for ( i = 1; i < arg_n; i++ ) {
		v = p_dt[i];
		j = i - 1;
		while ( (j >= 0) && (p_dt[j] > v) ) p_dt[j + 1] = p_dt[j--];
		p_dt[j + 1] = v;
		trace( p_dt, arg_n );
	}
}

int main( void ) {
	short i;
	unsigned short n, dt[MAX];

	scanf( "%d", &n );
	for ( i = 0; i < n; i++ ) scanf( "%d", &dt[i] );

	insertionSort( dt, n );

	return 0;
}

