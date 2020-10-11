#include<stdio.h>

#define N 2000001
#define MAX 10000

int A[N], B[N], C[MAX];

int main(void){
    int n;
    for(int i=0; i<MAX; i++){
        C[i]=0;
    }
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &A[i+1]);
        C[A[i+1]]++;
    }
    for(int i=1; i<MAX; i++){
        C[i]+=C[i-1];
    }
    for(int j=1; j<=n; j++){
        B[C[A[j]]]=A[j];
        C[A[j]]--;
    }
    for(int i=1; i<n; i++){
        printf("%d ",B[i]);
    }
    printf("%d\n",B[n]);

    return 0;

}


