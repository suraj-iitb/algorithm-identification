#include<stdio.h>

int bubblesort(int n,int A[]){
	int i,j;
	int N=0;
	int a;
	for(i=0;i<n;i++){
		for(j=n-1;j>i;j--){
			if(A[j-1]>A[j]){
				a=A[j-1];
				A[j-1]=A[j];
				A[j]=a;
				N++;
			}
		}
	}
	for(i=0;i<n-1;i++){
		printf("%d ",A[i]);
	}
	printf("%d",A[i]);
	return N;
}

int main(){
	int i,n,A[100];
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	printf("\n%d\n",bubblesort(n,A));

	return 0;
}
