#include <stdio.h>
void insertionSort(int *,int);
#define MAX 1001
int main(void){
	int n,i;
	int A[MAX];
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	insertionSort(A,n);
	return 0;
}

void insertionSort(int *A,int n){
	int i,j,tmp=0,a;
	for(i=0;i<n;i++){
		tmp=A[i];
		j = i-1;
		while(j >=0 && A[j] > tmp){
				A[j+1]=A[j];
				j--;
		}
		A[j+1]=tmp;
		for(a=0; a<n; a++){
			printf("%d",A[a]);
			if(a!=n-1)printf(" ");
		}
		printf("\n");
	}
}
