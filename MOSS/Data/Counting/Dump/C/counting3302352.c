#include<stdio.h>
#define N 2000000
#define M 10000

int A[N],B[N];

int main(){
    int n,i;
    int C[M];
    int k=M;
    scanf("%d",&n);
    for(i=0;i<k;i++)C[i]=0;
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
        C[A[i]]++;
    }
    for(i=1;i<=k;i++){
        C[i]=C[i]+C[i-1];
    }
    for(i=0;i<n;i++){
        B[C[A[i]]]=A[i];
        C[A[i]]--;
    }
    for(i=1;i<=n;i++){
        if(i!=n)printf("%d ",B[i]);
        else printf("%d",B[i]);
    }
    printf("\n");
    return 0;
}

