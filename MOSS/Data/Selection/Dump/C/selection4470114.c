#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void sort(int A[],int n){
	int tmp,t;
	int count=0;
	for(int i=0;i<(n);i++){
		t=i;
		for(int j=i;j<(n);j++){
			if(A[j]<A[t]){
				t=j;
			}
		}
		if(A[t]!=A[i]){
			tmp=A[i];
			A[i]=A[t];
			A[t]=tmp;
			count++;
		}
	}
	for(int i=0;i<n;i++){
		printf("%d",A[i]);
		if(i==(n-1)){
			printf("\n");
		}else{
			printf(" ");
		}
	}
	printf("%d\n",count);
}

int main(){
    int n;
	int *A;

	scanf("%d",&n);
	A=(int*)malloc(sizeof(int)*n);

	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}

	sort(A,n);	
	return 0;
}
