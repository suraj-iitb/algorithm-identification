#include <stdio.h>
#define N 2000001
#define M 10001
int A[N],B[N],C[M];
int main(){
  int a,i,j;
  scanf("%d",&a);
  for(i=0;i<=M;i++)
    C[i]=0;
  
  for(i=0;i<a;i++){
    scanf("%d",&A[i+1]);
    C[A[i+1]]++;
  }
  
  for(i=1;i<=M;i++)
    C[i]=C[i]+C[i-1];
  
  for(j=1;j<=a;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<=a;i++){
    if(i>1)printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  return 0;
}
    
   
