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
    int n, i, j, key;
    int A[N];
    scanf("%d", &n);

    for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);

    for(i = 1; i < n; i++)
    {
        trace(A, n);
        key = A[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (A[j] > key)
                A[j + 1] = A[j];
            else
                break;
        }
        A[j + 1] = key;
        
    }
    
    trace(A, n);

    return 0;
}
