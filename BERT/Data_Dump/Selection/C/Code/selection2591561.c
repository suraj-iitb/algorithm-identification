#include <stdio.h>

static const int N = 1000;

void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main(){
    int n, i, j, key, count = 0, temp;
    int A[N];
    scanf("%d", &n);

    for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
    
    for (i = 0; i < n; i++)
    {
        key = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[key]) key = j;
        }
        if (key != i)
        {A[i] = A[key] ^ A[i];
        A[key] = A[key] ^ A[i];
        A[i] = A[key] ^ A[i];
        count++;}
    }
    
    trace(A, n);
    printf("%d\n", count);

    return 0;
}
