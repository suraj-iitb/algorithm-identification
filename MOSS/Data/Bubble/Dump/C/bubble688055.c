#include <stdio.h>

int main( void ) {
	int i, j, tmp, cnt = 0, nData, data[ 100 ];

	scanf( "%d", &nData );

	for ( i = 0; i < nData; i++ )
		scanf( "%d", &data[ i ] );

	for ( i = 0; i < nData - 1; i++ )
		for ( j = nData - 1; j > i; j-- )
			if ( data[ j - 1 ] > data[ j ] ) {
				tmp = data[ j - 1 ];
				data[ j - 1 ] = data[ j ];
				data[ j ] = tmp;

				cnt++;
			}

	for ( i = 0; i < nData - 1; i++ )
		printf( "%d ", data[ i ] );
	printf( "%d\n%d\n", data[ nData - 1 ], cnt );

	return 0;
}
