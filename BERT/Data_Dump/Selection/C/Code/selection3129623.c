#include <stdio.h>

#define MAX 1000

int selectionSort( int *ary, int n )
{
        int i, j, minx, tmp, swp = 0;

        for ( i = 0 ; i < n ; i++ )
        {
                minx = i;
                for ( j = i ; j < n ; j++ )
                {
                        if ( ary[minx] > ary[j] )
                        {
                                minx = j;
                        }
                }

                if ( i != minx )
                {
                        tmp = ary[i];
                        ary[i] = ary[minx];
                        ary[minx] = tmp;
                        swp++;
                }
        }
        return swp;
}


int main()
{
        int n, i, swp;
        int ary[MAX];

        scanf( "%d", &n );
        for ( i = 0 ; i < n ; i++ )
        {
                scanf( "%d", &ary[i] );
        }

        swp = selectionSort( ary, n );
        for ( i = 0 ; i < n ; i++ )
        {
                if ( i != n-1 )
                {
                        fprintf( stdout, "%d ", ary[i] );
                }
                else
                {
                        fprintf( stdout, "%d\n", ary[i] );
                }
        }
        fprintf( stdout, "%d\n", swp );


        return 0;
}

