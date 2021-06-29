#include<stdio.h>

int binarySearch(int A[100000],int key,int n){
	int left=0;
	int right=n;
	int mid;
	
	while(left<right){
		mid=(left+right)/2;
		
		if(key==A[mid]){return 1;}
		else if(key>A[mid]){left=mid+1;}
		else{right=mid;}
	}	
		return 0;
}

int main(void){
	int A[100000];
	int i,q,key,cnt,n;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&key);
		if(binarySearch(A,key,n)){cnt++;}
	}
	
	printf("%d\n",cnt);
	
	return 0;
}

	

