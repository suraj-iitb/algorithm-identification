#include <stdio.h>

int search(int A[],int n,int key){
	int i;
	for(i=0;i<n;i++){
		if(key == A[i]){
			return 0;
		}
	}
return -1;
}
	
int main(void){

	int i,A[10000],n,q,key,sum=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&key);
		if(search(A, n, key) == 0){
			sum++;
		}
	}

	printf("%d\n",sum);
	
	return 0;
}

