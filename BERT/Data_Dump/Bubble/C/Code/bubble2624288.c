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

void bubbleSort(int *A,int n){
	int j,flag,tmp;
	int count = 0;
	flag = 1;
	while(flag){
		flag = 0;
		for(j=n-1;j>0;j--){
			if(A[j]<A[j-1]){
				tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
				count++;
				flag = 1;
			}
		}
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

	bubbleSort(A,n);

	return 0;
}
