#include<stdio.h>

int binary_search(int S[], int key, int n){
	int left = 0, right = n, mid;
	
	while( left < right ){
		mid = ( left + right ) / 2;
		if( S[mid] == key ){
			return 1;
		}
		else if(key > S[mid] ){
			left = mid + 1;
		}
		else{
			right = mid;
		}
	}
	
	return 0;
}

int main(void){
	int n, i, count = 0;
	
	scanf("%d", &n);
	
	int S[n];
	
	for( i = 0; i < n; i++ ){
		scanf("%d", &S[i]);
	}
	
	int q;
	
	scanf("%d", &q);
	
	int T[q];
	
	for( i = 0; i < q; i++ ){
		scanf("%d", &T[i]);
	}
	
	for( i = 0; i < q; i++ ){
		count += binary_search(S, T[i], n);
	}
	
	printf("%d\n", count);
	
	return 0;
}
