#include<stdio.h>
int n;
int C[10001];
void countingsort(int A[],int B[],int k){
    for(int j=0;j<n;++j)++C[A[j]];
    for(int i=1;i<=k;++i)C[i]+=C[i-1];
    for(int j=n-1;j>=0;--j){
        B[C[A[j]]-1]=A[j];
        --C[A[j]];
    }
}

int main(){
    int A[2000000],B[2000000];
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&A[i]);
    countingsort(A,B,10001);
    printf("%d",B[0]);
    for(int i=1;i<n;++i)printf(" %d",B[i]);
    printf("\n");
}
