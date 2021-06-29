#include<stdio.h>

int B[2000001],n;
void CountingSort(int[],int[],int);

int main(){
    int i,k=0;
    scanf("%d",&n);
    int A[2000001];
    for(i = 1 ; i <= n ; i++){
        scanf("%d",&A[i]);
        if(k < A[i]) k = A[i];
    }

    CountingSort(A,B,k);

    for(i = 1 ; i <= n ; i++){
        printf("%d",B[i]);
        if(i != n){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}

void CountingSort(int A[],int B[], int k){
    int i,C[k+1];
    for(i = 0 ; i <= k ; i++){
        C[i] = 0;
    }
    for(i = 1 ; i <= n ; i++){
        C[A[i]]++;
    }
    for(i = 1 ; i <= k ; i++){
        C[i] = C[i] + C[i-1];
    }
    for(i = n ; i >= 0; i--){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
}

