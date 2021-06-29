#include<stdio.h>

int main(){

	int i, j, n, A[100], minj, count,hako;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	count=0;
	
	for(i=0;i<n-1;i++){
		minj=i;
		for(j=i;j<n;j++){
			if(A[j]<A[minj]) minj=j;
		}
		hako = A[i];
		A[i]=A[minj];
		A[minj]=hako;
		if(minj!=i)count++;
	}
	
	for(i=0;i<n;i++){
		if(i!=n-1)printf("%d ",A[i]);
		else printf("%d\n%d\n",A[i],count);
	}
	
	return 0;
	}
