#include <stdio.h>

#define MAX 100

typedef unsigned char	U08;

static U08 Serection_Sort_U08( U08 *u08a_A, U08 u08_N );

int main()
{
	U08 u08_length;
	U08 u08a_sequence[MAX];
	U08 u08_idx;
	U08 u08_cnt;
	
	scanf("%d",&u08_length);
	
	for( u08_idx = 0; u08_idx < u08_length; u08_idx++ )
	{
		scanf("%d",&u08a_sequence[u08_idx]);
	}
	
	u08_cnt = Serection_Sort_U08( u08a_sequence, u08_length );
	
	for( u08_idx = 0; u08_idx < u08_length; u08_idx++ )
	{
		if( u08_idx == ( u08_length - 1 ) )
		{
			printf("%d\n",u08a_sequence[u08_idx]);
		}
		else
		{
			printf("%d ",u08a_sequence[u08_idx]);
		}
	}
	printf("%d\n",u08_cnt);
	
	return 0;
}

U08 Serection_Sort_U08( U08 *u08a_A, U08 u08_N )
{
	U08 u08_i;
	U08 u08_j;
	U08 u08_minj;
	U08 u08_buffer;
	U08 u08_flg = 0;
	U08 u08_swap = 0;
	
	for( u08_i = 0; u08_i < ( u08_N - 1 ); u08_i++ )
	{
		u08_minj = u08_i;
		
		for( u08_j = ( u08_i + 1 ); u08_j <= ( u08_N - 1 ); u08_j++ )
		{
			if( u08a_A[u08_j] < u08a_A[u08_minj] )
			{
				u08_minj = u08_j;
				u08_flg = 1;
			}
			else
			{
				//Do Nothing
			}
		}
		
		if( 0 != u08_flg )
		{
			u08_buffer = u08a_A[u08_minj];
			u08a_A[u08_minj] = u08a_A[u08_i];
			u08a_A[u08_i] = u08_buffer;
			u08_swap++;
			u08_flg = 0;
		}
	}
	return u08_swap;
}
