#include "stdio.h"

/*二分查找*/
int BinarySearch(int A[],int n,int key){
	int left=0,right = n;
	int mid;
	while(left < right){
		mid = (left+right) / 2;
		if(A[mid] == key) return 1;
		if(A[mid] < key) left = mid + 1;
		else if(A[mid] > key) right = mid;
	}
	return 0;
} 

int main(){
	int i,n,q,A[10000000],key,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) 
		scanf("%d",&A[i]);
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&key);
		if(BinarySearch(A,n,key)) sum++;
	}
	
	printf("%d\n",sum);
	return 0; 
} 
