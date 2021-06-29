#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char str[2000000]			= {};
	int S[10000]				= {};
	int T[500]					= {};
	int n						= 0;
	int q						= 0;
	int i						= 0;
	int j						= i;
	int k                       = 0;
	int num						= 0;
	fgets( str, 256, stdin );
	n = atoi(str);
	fgets( str, 2000000, stdin );
	
	while ( num < n ) {
		j = i;
		for ( i = 0; str[i] != ' ' && str[i] != '\r'; i++ ) {
		}
		str[i] = '\0';
		S[num] = atoi(&str[j]);
		for ( k = 0; k < num; k++ ) {
		    if ( S[num] == S[k] ) {
		        S[num] = -1;
		    }
		}
		num++;
		i++;
	}
	
	
	fgets( str, 256, stdin );
	q = atoi(str);
	fgets( str, 20000, stdin );
	i = 0;
	num = 0;
	while ( num < q ) {
		j = i;
		for ( i = 0; str[i] != ' ' && str[i] != '\r'; i++ ) {
		}
		str[i] = '\0';
		T[num] = atoi(&str[j]);
		num++;
		i++;
	}
	
	num = 0;
	
	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < q; j++ ) {
			if ( S[i] == T[j] ) {
				num++;
			}
		}
	}
	
	printf("%d\n", num);
	
	return 0;
}
