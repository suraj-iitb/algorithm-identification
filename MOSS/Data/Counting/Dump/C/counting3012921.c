#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  int i,j,n;
  unsigned short *A,*B;
  int C[VMAX+1];

  scanf("%d",&n);

  A=malloc(sizeof(short)*n+1);
  B=malloc(sizeof(short)*n+1);

  for(i=0;i<n;i++){
    scanf("%hu",&A[i+1]);
  }
  for(i=0;i<=VMAX;i++){
    C[i]=0;
  }
  for(j=0;j<n;j++){
    C[A[j+1]]++;
  }
  for(i=1;i<=VMAX;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=1;j<=n;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

 for(i=1;i<=n-1;i++){
   printf("%d ",B[i]);
      }
 printf("%d\n",B[n]);
  return 0;
}


