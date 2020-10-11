#include <stdio.h>
#include <stdbool.h>

static const int MAX = 100;

void swap(unsigned short *a, unsigned short *b ) {
	unsigned short temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

short bubbleSort( unsigned short *p_dt, unsigned short n ) {
	bool flag = true;
	short i, j, sw = 0;

	while ( flag ) {
		flag = false;
		for ( i = (n - 1); i >= 1; i-- ) {
			if ( p_dt[i] < p_dt[i - 1] ) {
				swap( &p_dt[i], &p_dt[i -1] );
				flag = true;
				sw++;
			}
		}
	}
	return sw;
}

int main( void ) {
	short i, sw;
	unsigned short n, dt[MAX];

	scanf( "%d", &n );
	for ( i = 0; i < n; i++ ) scanf( "%d", &dt[i] );

	sw = bubbleSort( dt, n );

	for( i = 0; i < (n - 1); i++ ) printf( "%d ", dt[i] );
	printf( "%d\n%d\n", dt[i], sw );

	return 0;
}

