#include<stdio.h>

#define MAX 100000
 
struct Cards {
	char pattern[2];
	int num;
	int order;
};
int flag=0;

void exchange( struct Cards *pa, struct Cards *pb )
{
	struct Cards t;
	
	t=*pa;
	*pa=*pb;
	*pb=t;

	return;
}

int Partition( struct Cards A[], int p, int r )
{
	struct Cards x;
	int i,j;

	x=A[r];
	i=p-1;
	for( j=p; j<r; j++ ) {
		if( A[j].num <= x.num ) {
			i++;
			exchange( &A[i], &A[j] );
		}

	}
	exchange( &A[i+1], &A[r] );

	return i+1;
}
void QuickSort( struct Cards A[], int p, int r )
{
	int q;
	
	if( p < r ) {
		q=Partition( A, p, r );
		QuickSort( A, p, q-1 );
		QuickSort( A, q+1, r );
	}
	return;
}
int isStable( int n, struct Cards A[], struct Cards B[] )
{
	int i;
	int lo,mi,hi;
	int res=0;
	int s,e,t;
	
	res=1;
    for( i=0; i<n; i++ ) {
        lo=0;
        hi=n;
        while( lo <= hi ) {
            mi=(lo+hi)/2; 
            if( B[i].num == A[mi].num ) {
            	if( A[mi].order ) {
            		if( A[ A[mi].order ].pattern[0] == B[i].pattern[0] ) {
		            	e=s=mi;
		            	while( B[i].num == A[s].num ) { s--; }
		            	s++;
		            	while( B[i].num == A[e].num ) { e++; }
		            	e--;

            			t=A[mi].order+1;
		            	while( s<=e ) {
		            		A[s++].order=t;
		        		}
            			res=1;
            		} else {
            			res=0;
            		}
            	} else {
	            	e=s=mi;
	            	while( B[i].num == A[s].num ) { s--; }
	            	s++;
	            	while( B[i].num == A[e].num ) { e++; }
	            	e--;
        			t=A[mi].order+1;
	            	while( s<=e ) {
	            		A[s++].order=t;
	        		}
        		     
        		}
                break;
            } else if( B[i].num < A[mi].num ) {
                hi=mi-1;
            } else {
                lo=mi+1;         
            }
        }
        if( !res ) {
        	break;
        }
    }
  
   return res;
}

int main( void ) 
{	
	int n,i;
	struct Cards A[MAX+1];
	struct Cards B[MAX+1];
		
    scanf( "%d", &n );
	for( i=0; i<n; i++ ) {
		scanf( "%s%d", A[i].pattern, &A[i].num );
		A[i].order=0;
		B[i]=A[i];
	}
	QuickSort( A, 0, n-1 );
	
	if( isStable( n, A, B ) ) {
		printf( "Stable\n" );
	} else {
		printf( "Not stable\n" );
	}
	for( i=0; i<n; i++ ) {
		printf( "%s %d\n", A[i].pattern, A[i].num );
	}

    return 0;
}
