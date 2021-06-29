#include<stdio.h>
#include<stdlib.h>
#define M 2000001
#define VM 10000

int main() {
  unsigned short *K,*X;

int C[VM+1];
 int n,i,j,z,q=0;
  scanf("%d",&n);



  for(z=0;z<n;z++){
     q += z;
     }



  K = malloc(sizeof(short)*n+1);
  X = malloc(sizeof(short)*n+1);

  for (i=0;i<=VM;i++)C[i]=0;

  for (i=0;i<n;i++){
    scanf("%hu",&K[i+1]);
    C[K[i+1]]++;
  }

  for (i=1;i<=VM;i++) C[i] = C[i] + C[i-1];

  for (j=1;j<=n;j++){
    X[C[K[j]]] = K[j];
    C[K[j]]--;
  }

  for (i=1;i<=n;i++){
    if(i>1) printf(" ");
    printf("%d",X[i]);
  }
  printf("\n");
  return 0;
}
