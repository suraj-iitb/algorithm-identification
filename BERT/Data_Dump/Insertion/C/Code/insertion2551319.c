#include <stdio.h>
#include <string.h>

#define N 100


void output( unsigned char n, int num[N]);


int main(int argc, char **argv)
{
	unsigned char i,j;
	unsigned char n;
	char inputs[100100];
	char *pointer;
	int num[N];
	int swap;
	
	

	fgets( inputs, sizeof(inputs), stdin );
	sscanf( inputs, "%d", &n );
	
	fgets( inputs, sizeof(inputs), stdin );
	pointer = strtok( inputs, " " );
	sscanf( pointer, "%d", &num[0] );
	for( i = 1; i < n; i++ ){
		pointer = strtok( NULL, " " );
		sscanf(pointer, "%d", &num[i]);
	}
	
	output(n, num);
	
	for( i = 0; i < n-1 ; i++ ){
		swap = num[i+1];
		for( j = i+1; j > 0; j--){
			if( num[j-1] < swap ) break;
			num[j] = num[j-1];
			num[j-1] = swap;
		}
		output( n, num );
	}
	
	return 0;

}



void output( unsigned char n, int num[N])
{
	char i;
	printf("%d", num[0]);
	for ( i = 1; i < n; i++ )
		printf(" %d", num[i]);
	printf("\n");
}
