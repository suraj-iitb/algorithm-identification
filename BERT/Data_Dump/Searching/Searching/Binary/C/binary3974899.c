#include<stdio.h>

int binarySearch(int n, int A[],int key){
	int left = 0;
	int right = n;

	while(left<right){
		int mid = (left+right)/2;
		if(A[mid]==key){
			return 1;
		}else if(key<A[mid]){
			right = mid;
		}else{
			left = mid+1;
		}
	}
	return 0;
}

int main(void){
	int n,i,q;

	scanf("%d",&n);

	int S[n];

	for(i=0;i<n;i++){scanf("%d",&S[i]);}

	scanf("%d\n",&q);

	int T[q];

	for(i=0;i<q;i++){scanf("%d",&T[i]);}

	int k=0;
	for(i=0; i<q; i++){
		k += binarySearch(n,S,T[i]);
	}

	printf("%d\n",k);

	return 0;
}

