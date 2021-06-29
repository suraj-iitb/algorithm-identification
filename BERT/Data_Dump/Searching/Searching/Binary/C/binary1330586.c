#include <stdio.h>
#define MAX 100000

int binarySearch(int);

int S[MAX],T[MAX],n=0;

int main(){

	int i,q,count=0;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
	}

	scanf("%d",&q);
	
	for(i=0;i<q;i++){
		scanf("%d",&T[i]);
	}

	for(i=0;i<q;i++){
		count += binarySearch(T[i]);
	}

	printf("%d\n",count);
	return 0;
}


int binarySearch(int key){
	int right=n,left=0,mid;

	while(left < right){
		mid = (left + right) / 2;
		if (S[mid] == key){
			return 1;
		}
		else if (key < S[mid]){
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return 0;
}
