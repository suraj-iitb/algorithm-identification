#include <stdio.h>
#define N 100

void printA(int *A,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d",A[i]);
		if(i!=n-1)printf(" ");
		else printf("\n");
	}
}

void selectionSort(int *A,int n){
	int i,j,minj;
	int tmp;
	int count = 0;
	for(i=0;i<n;i++){
		minj = i;
		for(j=i;j<n;j++){
			if(A[j]<A[minj])minj = j;
		}
		if(minj!=i){tmp = A[i];A[i]=A[minj];A[minj]=tmp;count++;}
	}
	printA(A,n);
	printf("%d\n",count);
}

int main(){
	int n;
	int i;
	int A[N];

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}

	selectionSort(A,n);

	return 0;
}
