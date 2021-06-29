#include <stdio.h>
#define MAX 2000001
void CountingSort(int, int);
int A[MAX], B[MAX];
int main(){
        int n, i, k=0;
            scanf("%d", &n);
        for(i= 0; i<n; i++) {
                     scanf("%d", &A[i]);
                if(k<A[i]) k = A[i];
        }

        CountingSort(k, n);

        for(i = 1; i<=n; i++) {
                printf("%d", B[i]);
                if(i<n) printf(" ");
        }
printf("\n");
        return 0;
}
void CountingSort(int k, int n){
        int C[MAX], i;

        for(i = 0; i<=k; i++)   C[i] = 0;
        for(i = 0; i<n; i++)  C[A[i]]++;
        for(i = 1; i<=k; i++) C[i] = C[i] + C[i - 1];
        for(i = n-1; i>=0; i--) {
                B[C[A[i]]] = A[i];
                C[A[i]]--;
        }
}
