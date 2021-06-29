#include <stdio.h>
#define MAX_LENGTH 2000001

int n, A[MAX_LENGTH], B[MAX_LENGTH], C[10001];

void CountingSort(int k){
    for (int ix = 0; ix < k; ix++)
        C[ix] = 0;
    for (int jx = 0; jx < n; jx++)
        C[A[jx]]++;
    for (int ix = 0; ix < k; ix++)
        C[ix+1] += C[ix];
    for (int jx = n-1 ; jx >= 0; jx--){
        B[C[A[jx]]-1] = A[jx];
        C[A[jx]]--;
    }
}
          
int main(){
    int k = -1;
    scanf("%d\n",&n);
    for (int ix = 0; ix < n; ix++){
        scanf("%d",&A[ix]);
        if ( k < A[ix]) k = A[ix];
    }
    CountingSort(k);
    for (int ix = 0; ix < n; ix++){
        if (ix != n-1) printf("%d ",B[ix]);
        else printf("%d\n",B[ix]);
    }    
    return 0;
}
