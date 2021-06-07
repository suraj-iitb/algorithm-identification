#include <stdio.h>
#define M 100000

int binarySearch(int [ ], int , int );

int main (){
	int n, S[M],q,i,fact;
	int count = 0;
	scanf("%d",&n);
	for(i = 0; i < n ; i++){
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
	for(i = 0; i < q ; i++){
		scanf("%d",&fact);
		if( binarySearch(S,n,fact)) count++;
	}
	printf("%d\n",count);
}

int binarySearch(int R[ ],int n,int x) {
	int left = 0;
	int right = n;
	int mid;
	while(left < right){
		mid = (left + right) /2;
		if(R[mid] == x){
			return mid;
		}else if(x < R[mid]){
			right = mid;
		}else {
			left = mid +1;
		}
	}
	return 0;
}
