#include <stdio.h>
#define K 10001
#define N 2000001

void CountingSort(short *A, short *B, int n){
    int i;
    int Count[K];

    for(i=0; i<K; i++) Count[i] = 0;
    for(i=1; i<=n; i++) Count[A[i]]++;

    for(i=1; i<=K; i++) Count[i] += Count[i-1];
    for(i=n; i>0; i--){
        B[Count[A[i]]] = A[i];
        Count[A[i]]--;
    }
} 

int main(){
    int i,n;
    short A[N],B[N];

    scanf("%d",&n);
    for(i=1; i<=n; i++){
        scanf("%d",&A[i]);
    }

    CountingSort(A,B,n);

    for(i=1; i<=n; i++){
        printf("%d",B[i]);
        if(n-i) printf(" "); 
    }
    printf("\n");
    return 0;
}
