#include<stdio.h>

#define NMAX 100000

int binarySearch(int A[], int n, int key){
	int i = 0, left = 0, right = n;
	int mid;
	while(left < right){
		mid = (left + right) / 2;
		if(A[mid] == key){
			return 1;
		}
		else if(key < A[mid]){
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	return 0;
}

int main(void){
	int x,i,n,q,key,sum = 0;
	int A[NMAX+1];
	scanf("%d" ,&n);
	for(i = 0; i < n; i++){
		scanf("%d" ,&A[i]);
	}
	scanf("%d" ,&q);
	for(i = 0; i < q; i++){
		scanf("%d" ,&key);
		x = binarySearch(A,n,key);
		if(x != 0){
			sum++;
		}
	}
	printf("%d\n" ,sum);
	return 0;
}
