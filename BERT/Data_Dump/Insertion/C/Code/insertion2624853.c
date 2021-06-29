#include<stdio.h>

void trace(int A[], int N){
    int i ;
    for(i=0; i<N;i++){
        if(i>0){
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
}
void intsertionSort(int A[], int N){
    int i,j,v;
    for(i=1;i<=N-1;i++){
        v = A[i];
        j = i -1;
        while(j>=0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace (A, N);
    }
}

int main(){
    int a,i,num[100];
    scanf("%d",&a);
    for(i=0;i<a;i++){
        scanf("%d",&num[i]);        
    }
    trace(num, a);
    intsertionSort(num,a);
}
