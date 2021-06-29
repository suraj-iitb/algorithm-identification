#include<stdio.h>
#define N 100

void trace(int *,int);
void insertionSort(int *,int);

int main(){
    int n,i,A[N];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    trace(A,n);
    insertionSort(A,n);

    return 0;
}

void insertionSort(int *A,int n){
    int i,j,v;
    for(i=1;i<n;i++){
        v=A[i];
        j=i-1;
        while(j>=0&&v<A[j]){
            A[j+1]=A[j];
            A[j]=v;
            j--;
        }
        trace(A,n);
    }
}

void trace(int *A,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d",A[i]);
        if(i!=n-1)printf(" ");
    }
    printf("\n");
}
