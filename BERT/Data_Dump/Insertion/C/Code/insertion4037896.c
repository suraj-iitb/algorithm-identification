#include <stdio.h>

void print(int A[],int N){
    int i;
    for(i=0;i<N;i++){
        if(i>0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}

void insertionsort(int A[],int N){
    int i,j,k;
    for(i=1;i<N;i++){
        k=A[i];
        j=i-1;
        while(j>=0 &&A[j]>k){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=k;
        print(A,N);
    }
}

int main(){
    int i,j,N;
    int A[1000];
    
    scanf("%d",&N);
    for(i=0;i<N;i++)
    scanf("%d",&A[i]);
    
    print(A,N);
    insertionsort(A,N);
    
    return 0;
}

