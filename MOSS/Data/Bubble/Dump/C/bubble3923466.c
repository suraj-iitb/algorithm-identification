#include<stdio.h>
int main(void){
	
	int n,i,j,jump,cnt=0;
	scanf("%d",&n);
	
	int A[n];
	
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	
	for(j=0;j<n-1;j++){
		for(i=n-1;i>j;i--){
			if(A[i]<A[i-1]){
				jump=A[i];
				A[i]=A[i-1];
				A[i-1]=jump;
				cnt++;
				
			}
		}
	}
	
	for(i=0;i<n-1;i++){
		printf("%d ",A[i]);
	}
	printf("%d\n",A[i]);
	printf("%d\n",cnt);
	return 0;
}
