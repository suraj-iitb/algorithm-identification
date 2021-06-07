#include <stdio.h>

int linearSearch(int A[],int m,int key){
	int i = 0;
	A[m] = key;
	while (A[i]!=key) {
		i++;
		if(i==m) return 0;
	}
	return 1;
}

int main(void){
	int m,n,i,key;
	int A[10000+1];
	int count =0;
	
	scanf("%d",&m);
	
	for(i=0;i<m;i++){
		scanf("%d",&A[i]);
	}
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&key);
		count= count+ linearSearch(A,m,key);
	}
	
	printf("%d\n",count);
	return 0;
}
