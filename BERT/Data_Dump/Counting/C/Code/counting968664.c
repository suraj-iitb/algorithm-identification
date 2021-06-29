#include <stdio.h>
#define N 2000001
#define MAX 10000
void Counting_Sort(int);
int A[N];
int B[N];
int C[N];
int n;
int main(){
    int i;
    int k=0;
    scanf("%d", &n);
    for( i=1; i<=n; i++ ){
        scanf("%d", &A[i]);
        if( A[i] > MAX ) return 0;
        else if( k < A[i] ) k=A[i];
    }
    Counting_Sort(k);
    for( i=1; i<=n; i++ ){
        printf("%d", B[i]);
        if( i+1 <= n ){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
void Counting_Sort(int k){
    int i;
    for( i=0; i<=k; i++ ) C[i]=0;
    for( i=1; i<=n; i++ ) C[A[i]]++;
    for( i=1; i<=k; i++) C[i]+=C[i-1];
    for( i=n; i>0; i-- ){
        B[C[A[i]]]=A[i];
        C[A[i]]--;
    }
}
