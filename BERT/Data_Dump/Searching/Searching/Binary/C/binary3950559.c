#include<stdio.h>
int binarySearch(int n,int A[],int key);
int main(void){
	
	int n,q,S[1000000],T[1000000],i,count=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&T[i]);
	}
	
	for(i=0;i<q;i++){
		if(binarySearch(n,S,T[i])!=0){
			count++;
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}

int binarySearch(int n,int A[],int key){
	
	int left=0,right=n,mid;
	
	while(left<right){
		mid=(left+right)/2;
		if(A[mid]==key){
			return 1;
		}
		else if(key<=A[mid]){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	
	return 0;
}
