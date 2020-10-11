#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	int i;
	int j;
	int *A;
	scanf("%d", &n);
	A = (int*) malloc(sizeof(int) * n);
	for(i=0;i<n;++i)scanf("%d", &A[i]);
	for(j=0;j<n;++j){
		int d = A[j];
		i = j - 1;
		while(i>=0&&A[i]>d){
			A[i+1] = A[i];
			--i;
		}
		A[i+1] = d;
		for(i=0;i<n;++i){
			if(i)printf(" ");
			printf("%d", A[i]);
		}
		printf("\n");
	}
	return 0;
}

