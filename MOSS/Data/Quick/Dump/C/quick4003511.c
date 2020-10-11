#include<stdio.h> 
#define MAX 100000
#define INFTY 1000000000

struct Card{
	char suit;
	int value;
};

struct Card L[MAX/2+2] , R[MAX/2+2];

void merge(struct Card A[], int left, int mid, int right){

	int n1 , n2;
	int i , j , k;
	
	n1 = mid - left;
	n2 = right - mid;
	
	for( i = 0; i < n1; i++ ){
		L[i] = A[left + i];
	}
	for( i = 0; i < n2; i++ ){
		R[i] = A[mid + i];
	}
	
	L[n1].value = R[n2].value = INFTY;
	
	i = 0;
	j = 0;
	
	for ( k = left; k < right; k++ ){
		
		if( L[i].value <= R[j].value ){
			A[k] = L[i];
			i++;
		}else{
			A[k] = R[j];
			j++;
		}
	}
}

void mergeSort(struct Card A[], int left, int right){
	
	int mid;
	
	if ( left+1 < right ){
		
		mid = (left + right)/2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
		
	}
	
}

int partition( struct Card A[] , int p , int r ){
	
	struct Card x,temp;
	int i;

	x = A[r];
	i = p - 1;
	
	for( int j = p; j < r; j++ ){
		
		if( A[j].value <= x.value ){
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
		
	}
	
	temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;
	
	return i + 1;
	
}

void quickSort(struct Card A[] , int p , int r ){
	
	int q;
	if( p < r ){
		q = partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

int stablesort( struct Card A[] , struct Card B[] , int n ){
	
	int i;
	
	for( i = 0; i < n; i++ ){
		if( A[i].suit != B[i].suit ){ return 0; }
	}
	
	return 1;
}

int main( void ){
	
	int n;
	struct Card M[MAX],Q[MAX];
	int i;
	char S[10];
	int v;
	
	scanf( "%d" , &n );
	
	for( i = 0; i < n; i++ ){
		scanf( "%s %d" , S , &v );
		M[i].suit = Q[i].suit = S[0];
		M[i].value = Q[i].value = v;
	}
	
	mergeSort(M,0,n);
	quickSort(Q,0,n-1);
	
	if( stablesort( M , Q , n ) == 1 ){
		printf( "Stable\n" );
	}else{
		printf( "Not stable\n" ); 
	}
	
	for( i = 0; i < n; i++ ){
		printf( "%c %d\n" , Q[i].suit , Q[i].value );
	}
	
}
