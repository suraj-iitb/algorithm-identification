#include <stdio.h>
int n;
int C[10001];
void CountingSort(int A[],int B[],int k){
    int i,j;
    for(i=0;i<k;i++){
        C[i]=0;
    }
    for(j=1;j<=n;j++){
        C[A[j]]++;
    }
    for(i=1;i<=k;i++){
        C[i]=C[i]+C[i-1];
    }
    for(j=n;j>=1;j--){
        B[C[A[j]]]=A[j];
        C[A[j]]--;
    }
}
int main(){
    int i,MAX=0;
    int *A,*B;
    scanf("%d",&n);
    A = malloc(sizeof(int)*n+1);
    B = malloc(sizeof(int)*n+1);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
        if(MAX<A[i]){
            MAX=A[i];
        }
    }
    CountingSort(A,B,MAX);
    for(i=1;i<=n-1;i++){
        printf("%d ",B[i]);
    }
    printf("%d\n",B[i]);
}
