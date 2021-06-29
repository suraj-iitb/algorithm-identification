#include <stdio.h>
void selectionSort(int *A,int N){
	int i,j,minj,t,count=0;
	for(i=0;i<N;i++){
		minj=i;
		for(j=i;j<N;j++){
			if(A[j]<A[minj]){
				minj=j;
			}
		}
		if(i!=minj){
			t=A[i];
			A[i]=A[minj];
			A[minj]=t;
			count++;
		}
	}
    for(i=0;i<N-1;i++) printf("%d ",A[i]);
    printf("%d\n",A[N-1]);
    printf("%d\n",count);
}
int main(void){
	int N,a,i;
	int A[100];
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&a);
		A[i]=a;
	}
	selectionSort(A,N);
	return 0;
}

