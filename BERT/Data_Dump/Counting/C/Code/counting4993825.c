#include<stdio.h>
int max(int a,int b){
    return a>b? a:b;
}
void CountingSort(int A[],int k,int n){
    int i,j,B[2000002],C[2000002];
    for(i=0;i<=k;i++){
        C[i]=0;
    }
    for(j=1;j<=n;j++){
        C[A[j]]++;
    }
    for(i=1;i<=k;i++){
        C[i]=C[i]+C[i-1];
    }
    for(j=n;j>0;j--){
        B[C[A[j]]]=A[j];
        C[A[j]]--;
    }
    for(i=1;i<=n;i++){
        if(i>1){
            printf(" ");
        }
        printf("%d",B[i]);
    }
    printf("\n");
    return;
}
int main(){
    int i,n,k=0,A[2000002];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i+1]);
        k=max(k,A[i]);
    }
    CountingSort(A,k,n);
    return 0;
}
