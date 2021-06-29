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
    int n, i, j, done, count = 0;
    int A[N];
    scanf("%d", &n);

    for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);

    done = 1;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                A[j] = A[j + 1] ^ A[j];
                A[j + 1] = A[j + 1] ^ A[j];
                A[j] = A[j + 1] ^ A[j];
                done = 0;
                count++;
            }
        }
        if(done == 1)
            break;
    }
    
    trace(A, n);
    printf("%d\n", count);

    return 0;
}
