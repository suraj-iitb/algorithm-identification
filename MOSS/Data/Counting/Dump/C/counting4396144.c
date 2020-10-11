#include <stdio.h>
#define MAX 2000000

int n;

void CountingSort(int A[], int B[], int k) {
    int C[k];
    
    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        C[A[i]]++;
    }
    
    for (int i = 1; i <= k; i++) {
        C[i] += C[i-1];
    }
    
    for (int i = n-1; i >= 0; i--) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
    
}

int main(void){
   int A[MAX], B[MAX], k = 0;
   
   scanf("%d", &n);
   
   for (int i = 0; i < n; i++) {
       scanf("%d", &A[i]);
       if (k < A[i]) k = A[i];
   }

   
   CountingSort(A, B, k);
   
   for (int i = 1; i <= n; i++) {
       if (i-1) printf(" ");
       printf("%d", B[i]);
   }
printf("\n");
   return 0;
    
}

