#include<stdio.h>

#define MAX 500000
#define SENTINEL 1000000001

int gS[MAX+1],gn,cnt;
int gL[ (MAX/2)+1 ],gR[ (MAX/2)+1 ];

void merge( int left, int mid, int right )
{
	int i,j,k;
	int n1=mid-left;
	int n2=right-mid;

	for( i=0; i<n1; i++ ) {
    	gL[i]=gS[ left+i ];
    }
	for( i=0; i<n2; i++ ) {
    	gR[i]=gS[ mid+i ];
    }
    
	gL[n1]=gR[n2]=SENTINEL;
	i=j=0;
	for( k=left; k<right; k++ ) {
		cnt++;
		if( gL[i] <= gR[j] ) {
			gS[k]=gL[i++];
		} else {
			gS[k]=gR[j++];
		}
    }
	return;
}

void mergeSort( int left, int right )
{	
	int mid;
	if( left+1 < right ) {
		mid=(left+right)/2;
		mergeSort( left, mid );
		mergeSort( mid, right );
		merge( left, mid, right );
	}
	
	return;
}


int main( void ) 
{
    scanf( "%d", &gn );
    
	int i;
	for( i=0; i<gn; i++ ) {
		scanf( "%d", &gS[i] );
	}
	cnt=0;
	mergeSort( 0, gn );

	for( i=0; i<gn; i++ ) {
		printf("%d", gS[i] );
		if( i < gn-1 ) { printf( " " ); }
	}
	printf( "\n%d\n", cnt );
	
    return 0;
}
