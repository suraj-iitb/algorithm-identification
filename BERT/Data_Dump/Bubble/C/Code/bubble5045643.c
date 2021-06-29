#include<stdio.h>

int main(){

	int i, j, n, hako, A[100], count;
	
	count=0;
	
	scanf("%d",&n);
	
	for(i=0; i<n; i++){
		scanf("%d",&A[i]);
		}
	
		for(i=0; i<n-1;i++){
			for(j=n-1;j>=i+1;j--){
				if(A[j]<A[j-1]){
					hako = A[j];
					A[j] = A[j-1];
					A[j-1] = hako;
					count++;
					}
				}
			}
			
	for(i=0;i<n;i++){
		if(i != n-1){
			printf("%d ",A[i]);
		}
		else{
			printf("%d\n%d\n",A[i],count);
		}
	}
	return 0;
}
