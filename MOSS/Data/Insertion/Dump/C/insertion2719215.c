#include <stdio.h>

#define SIZE_MIN ((int) 1)
#define SIZE_MAX ((int) 100)
#define ELEMENT_MIN ((int) 0)
#define ELEMENT_MAX ((int) 1000)

typedef enum
{
	kSuccess = 0,
	kError = -1
}Result;

Result checkNumRange( int num, int min, int max );
void showArray( int *arr, int size );
void execInsertuinSort( int *array, int size );

int main( void )
{
	int i, size, array[SIZE_MAX];

	scanf( "%d", &size );
	if( checkNumRange( size, SIZE_MIN, SIZE_MAX ) == kError )
	{
		return kError;
	}

	for( i = 0; i < size; i++ )
	{
		scanf( "%d", &array[i] );
		if( checkNumRange( array[i], ELEMENT_MIN, ELEMENT_MAX ) == kError )
		{
			return kError;
		}
	}

	showArray( array, size );
	execInsertuinSort( &array[0], size );

	return kSuccess;
}

Result checkNumRange( int num, int min, int max )
{
	return ((num >= min) && (num <= max)) ? kSuccess : kError;
}

void showArray( int *array, int size )
{
	int i;

	for( i = 0; i < size - 1; i++ )
	{
		printf( "%d ", array[i] );
	}
	printf( "%d\n", array[size - 1] );
}

void execInsertuinSort( int *array, int size )
{
	int i, j, work;

	for( i = 1; i < size; i++ )
	{
		work = array[i];
		j = i - 1;

		while( (j >= 0) && (array[j] > work) )
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = work;

		showArray(array, size);
	}
}

