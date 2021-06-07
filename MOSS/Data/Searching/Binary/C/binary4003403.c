#include <stdio.h>

int A[1000000],t;

int binarySearch(int k){
	int left = 0,right = t;
	int mid;
	for(;left < right;){
		mid = (left+right)/2;
		if(k == A[mid])return 1;
		if(k > A[mid])left = mid +1;
		else if(k < A[mid]) right = mid;
	}
	return 0;
}

int main(void){
	int i,m,k;
	int sum = 0;
	
	scanf("%d",&t);
	for(i = 0;i < t;i++){
		scanf("%d",&A[i]);
	}
	
	scanf("%d", &m);
	for(i = 0;i < m; i++){
		scanf("%d",&k);
		if(binarySearch(k) == 1)sum++;
	}
	printf("%d\n",sum);
	return 0;
	
}
