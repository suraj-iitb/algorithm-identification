#include<stdio.h>

void insertionSort(int A[], int n){
	int i,j,k;
	int v;
	for(i=1;i<n;i++){
		v=A[i];
		j=i-1;
		while(j>=0 && A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		for(k=0;k<n-1;k++) printf("%d ",A[k]);
		printf("%d",A[k]);
		printf("\n");
	}
}

int main(void)
{
	int N;
	scanf("%d",&N);
	int Num[N];
	int i;
	for(i=0;i<N;i++) scanf("%d",&Num[i]);
	for(i=0;i<N-1;i++) printf("%d ",Num[i]);
    printf("%d",Num[i]);
	printf("\n");
	insertionSort(Num,N);
	return 0;
}
