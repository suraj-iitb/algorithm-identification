#include <stdio.h>
void insertionSort(int *A,int N){
    int i,j,v;
    for(i=1;i<N;i++){
    	for(j=0;j<N-1;j++) printf("%d ",A[j]);
    	printf("%d\n",A[N-1]);
        v=A[i];
        j=i-1;
        while(j>=0&&A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
    }
    for(i=0;i<N-1;i++) printf("%d ",A[i]);
    printf("%d\n",A[N-1]);
}
int main(void){
	int N,a,i;
	int A[100];
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&a);
		A[i]=a;
	}
	insertionSort(A,N);
	return 0;
}

