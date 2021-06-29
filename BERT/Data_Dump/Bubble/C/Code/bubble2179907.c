#include <stdio.h>

void swap(int *a, int *b);

int main(){
	int i,n,A[100],counter=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}

	int flag=1;
	while(flag){
		flag=0;
		for(i=n-1;i>=1;i--){
			if(A[i]<A[i-1]){
				swap(&A[i],&A[i-1]);
				flag=1;
				counter++;
			}
		}
	}

	for(i=0;i<n;i++){
		printf("%d",A[i]);
		if(i<n-1) printf(" ");
	}
	printf("\n%d\n",counter);

	return 0;
}

void swap(int *a, int *b){
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
