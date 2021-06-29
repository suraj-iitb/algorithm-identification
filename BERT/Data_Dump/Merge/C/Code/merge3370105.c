#include<stdio.h>
#define MAX 500000
#define SENTINEL 1000000001

int S[MAX+1],n,cnt;
int L[(MAX/2)+1],R[(MAX/2)+1];

void merge( int left, int mid, int right ){
	int i,j,k;
	int n1=mid-left;
	int n2=right-mid;

	for( i = 0; i < n1; i++ ) {
    	L[i]=S[left+i];
    }
	for( i = 0; i < n2; i++ ) {
    	R[i]=S[mid+i];
    }
    
	L[n1]=R[n2]=SENTINEL;
	i=j=0;
	for( k = left; k < right; k++ ) {
		cnt++;
		if( L[i] <= R[j]) 
			S[k]=L[i++];
		else 
			S[k]=R[j++];
    }
	return;
}

void mergeSort(int left, int right){	
	int mid;
	if( left+1 < right) {
		mid=(left+right)/2;
		mergeSort(left, mid);
		mergeSort(mid, right);
		merge(left, mid, right);
	}
	return;
}


int main() {
    scanf("%d", &n );
    
	int i;
	for( i=0; i<n; i++ ) {
		scanf("%d", &S[i] );
	}
	cnt=0;
	mergeSort( 0, n );

	for( i = 0; i < n; i++ ) {
		printf("%d", S[i] );
		if( i < n-1 ) 
		    printf( " " ); 
	}
	printf("\n%d\n", cnt);
	
    return 0;
}

