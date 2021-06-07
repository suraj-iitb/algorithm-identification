#include<stdio.h>
#define NOT_FOUND 100000000

int binarySearch(int A[], int n, int key){
    int left, right, mid;
	
	
	
	left = 0;
    right = n;
	while (left < right){
        mid = (left + right) / 2;
		if (A[mid] == key) return mid;//見つけた
		else if (key < A[mid]) right = mid;
        else left = mid + 1;
	}
    return NOT_FOUND;
}


int main(void){
	
	int n, i, q;
	
	scanf("%d", &n);
	int S[n];
	
	for(i=0; i<n; i++){
		scanf(" %d", &S[i]);
		//printf("S%d\n", S[i]);
	}
	
	scanf("%d", &q);
	int T[q];
	
	for(i=0; i<q; i++){
		scanf(" %d", &T[i]);
		//printf("T%d\n", T[i]);
	}
	
	int k=0, a, A[q];
	
	for(i=0; i<q; i++){
		a = binarySearch(S, n, T[i]);
		if(a!=NOT_FOUND){//あった
			A[k]=a;
			k++;
		}
	}
	
	
	printf("%d\n", k);
	/*for(i=0; i<k-1; i++){
		printf("%d ", A[i]);
	}
	printf("%d", A[k]);
	*/
	
	return 0;
}
