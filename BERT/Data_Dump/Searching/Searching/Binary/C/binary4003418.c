#include <stdio.h>

int BinarySearch(int A[],int n,int key){
	int left = 0;
	int right = n;
	int mid;
	while(left < right){
		mid = (left + right) / 2;
		if(A[mid] == key){
			return mid;
		}
		else if(key < A[mid]){
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	return -1;
}

int main(void){
	int i,n,q,key,sum=0;
	int A[100000];
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&key);
		if(BinarySearch(A,n,key)!=-1){
			sum=sum+1;
		}
	}
	
	printf("%d\n",sum);

	return 0;
}
