#include <stdio.h>

int n, C[2000000], A[2000001], B[2000001];;

void CountingSort(int k){
    int i, j;
    for(i = 0; i<=k; i++){
      C[i] = 0;
    }
    for(j = 1; j<=n; j++){
      C[A[j]]++;
    }
    for(i = 1; i<=k; i++){
      C[i] += C[i-1];
    }
    for(j = n; j>0; j--){
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }

}

int main(){
  int i, max = 0;

    scanf("%d", &n);

    for(i = 1; i<=n; i++){
        scanf("%d", &A[i]);
        if(max< A[i])max = A[i];
    }

    CountingSort(max);

    for(i = 1; i<n; i++){
        printf("%d ", B[i]);
    }

    printf("%d\n", B[i]);

    return 0;
}
