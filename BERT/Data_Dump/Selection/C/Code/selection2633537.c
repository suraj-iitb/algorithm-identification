#include<stdio.h>

/*void trace(int A[], int N){
    int i ;
    printf("%d", A[0]);
    for(i=1; i<N;i++){
            printf(" %d", A[i]);
    }
    printf("\n");
}*/
void trace(int A[], int N){
    int i;
    for(i=0;i<N-1;i++) printf("%d ",A[i]);
    printf("%d\n",A[N-1]);
}
 

void intsertionSort(int A[], int N){
    int i,j,minj,temp,count=0;
    for(i=0;i<=N-1;i++){
        minj = i;
        for(j=i;j<=N-1;j++){
            if (A[j] < A[minj]){
                minj = j;
            }
        }
        if(i!=minj){
            temp = A[i];
            A[i] = A[minj];
            A[minj] = temp;
            count++;
        }
    }
    trace(A,N);
    printf("%d",count);
    printf("\n");
}

int main(){
    int a,i,num[100];
    scanf("%d",&a);
    for(i=0;i<a;i++){
        scanf("%d",&num[i]);        
    }
    intsertionSort(num,a);

}
