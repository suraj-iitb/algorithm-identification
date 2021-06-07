#include <stdio.h>

int n, cnt = 0;

int binary_search(int *A, int key){
	int left, mid, right;
	left = 0;
	right = n;
	
	while(left<right){
		mid = (left+right)/2;
		if(A[mid]==key){
			return mid;
		}else if(A[mid]<key){
			left = mid+1;
		}else{
			right = mid;
		}
	}
	return -1;
}

int main(){
	int A[100011], B[100011], a, b;
	int i, j;
	
	scanf("%d", &a);
	for(i=0;i<a;i++){
		scanf("%d", &A[i]);
	}
	
	scanf("%d", &b);
	for(j=0;j<b;j++){
		scanf("%d", &B[j]);
	}
	
	n=a;
	
	for(j=0;j<b;j++){
		if(binary_search(A, B[j])!=-1) cnt++;
	}
	
	printf("%d\n", cnt);
	return 0;
}

