#include <stdio.h>

int LinearSearch(int A[],int n,int key){
	int i;
	for(i=0;i<n;i++){
		if(A[i]==key){
			return i;
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
		if(LinearSearch(A,n,key)!=-1){
			sum=sum+1;
		}
	}
	
	printf("%d\n",sum);

	return 0;
}
