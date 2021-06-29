#include <cstdio>
int n;
int C[10001];
void CountingSort(int* A, int* B, int k){
    for (int i = 0 ; i <= k ;++i)
        C[i] = 0;

    /* C[i] に i の出現数を記録する */
    for (int j = 0 ; j < n ; ++j)
        C[A[j]]++;

    /* C[i] に i 以下の数の出現数を記録する*/
    for (int i = 1 ; i <= k ; ++i)
        C[i] = C[i] + C[i-1];

    for (int j = n-1 ; j >= 0 ; --j){
        B[C[A[j]]-1] = A[j];
        C[A[j]]--;
    }
}

int a[2000000];
int b[2000000];
int main(){
  scanf("%d", &n);
  for (int i=0;i<n;i++){
    scanf("%d", a+i);
  }
  CountingSort(a, b, 10000);
  for (int i=0;i<n;i++){
    if (i!=0) printf(" ");
    printf("%d", b[i]);
  }
  printf("\n");
  return 0;
} 

