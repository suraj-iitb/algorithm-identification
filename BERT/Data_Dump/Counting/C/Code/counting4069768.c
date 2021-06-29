#include <stdio.h>



int A[2000001],B[2000001],n;
void CountingSort(int *,int *,int k);

int main(){
    int i,j,mx=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
        if(mx<A[i]) mx = A[i];
    }
    CountingSort(A,B,mx);
    return 0;
}

void CountingSort(int A[],int B[],int k){
    int i,j;
    int C[10001];

    for(i=0;i<=k;i++){
        C[i] = 0;
    }

    for(j=0;j<n;j++){
        C[A[j]]++;
    }
    for(i=1;i<=k;i++){
        C[i] += C[i-1];
    }

    for(j=n-1;j>=0;j--){
        B[C[A[j]]-1] = A[j];
        C[A[j]]--;
    }

    for(i=0;i<n;i++){
        printf("%d",B[i]);
        if(i != n-1) printf(" ");
    }
    printf("\n");
}
