  /*テンプレート引用*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);
 int  k = VMAX;
  /* your code */
  //conting sort(A,B,K)

  for(i=0;i<=k;i++){/*for i = 0 to k  C[i] = 0*/
    C[i] = 0;
  }

  /* C[i] に i の出現数を記録する */
  for(j = 1;j<=n;j++){/*for j = 1 to n  C[A[j]]++*/
    scanf("%hu",&A[j]);
    C[A[j]]++;
  }

  /* C[i] に i 以下の数の出現数を記録する*/
  for(i = 1;i<=k;i++){/*for i = 1 to k  C[i] = C[i] + C[i-1]*/
    C[i] = C[i] + C[i-1];
  }
   for(j = n;j>=1;j--){/*for j = n downto 1 B[C[A[j]]] = A[j] C[A[j]]--*/
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i = 1;i<=n;i++){
    if(i>1){
      printf(" ");
    }
    printf("%d",B[i]);
  }
  printf("\n");

    return 0;
}

