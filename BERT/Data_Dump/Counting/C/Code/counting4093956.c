#include <stdio.h>
#include <stdlib.h>
#define n 2000001
#define A 10000

int main(){
  int a;
 int *D,*B;
 int i,j;
  int C[A];
  scanf("%d", &a);
  
  D = malloc(sizeof(int)*a+1);
  B = malloc(sizeof(int)*a+1);
  
  for(i=0;i <= A ;i++)C[i]=0;
  
  for(i=0;i<a;i++){
    scanf("%d",&D[i+1]);
    C[D[i+1]]=C[D[i+1]]+1;
  }
  for(i=1;i<=A;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=1;j<=a;j++){
    B[C[D[j]]]=D[j];
 C[D[j]]=C[D[j]]-1;
  }
  for(j=1;j<=a;j++){
    if(j>1)printf(" ");
    printf("%d",B[j]);	
  }
  printf("\n");
  return 0;
}

