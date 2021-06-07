#include<stdio.h>

int search(int S[], int key, int n){
	int i, count = 0;
	
	for( i = 0; i < n; i++ ){
		if( S[i] == key ){
			count++;
		}
	}
	
	return count;
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
		if( search(S, T[i], n) >= 1 ){
			count++;
		}
	}
	
	printf("%d\n", count);
	
	return 0;
}
