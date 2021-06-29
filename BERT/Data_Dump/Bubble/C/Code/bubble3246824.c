#include <stdio.h>
void bubbleSort(int *A,int N){
	int flag,j,count=0,t;
    flag=1;
    while(flag){
        flag=0;
        for(j=N-1;j>0;j--){
            if(A[j]<A[j-1]){
            	count++;
                t=A[j];
                A[j]=A[j-1];
                A[j-1]=t;
                flag=1;
            }
        }
    }
    for(j=0;j<N-1;j++) printf("%d ",A[j]);
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
	bubbleSort(A,N);
	return 0;
}

