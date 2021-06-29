#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int n, i, j, c, k=VMAX;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(c=1;c<=n;c++){
    scanf("%hu",&A[c]);
    //C[A[c]]++;
  }

  
  for(i=0;i<=k;i++){
    C[i]=0;
  }
  
  for(j=1;j<=n;j++){
    C[A[j]]++;
  }
  
  for(i=1;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }
  
  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
    }

  for(c=1;c<n;c++){
    printf("%hu ",B[c]);
  }
  printf("%hu\n",B[n]);

  return 0;
}

