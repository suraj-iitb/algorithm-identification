#include <stdio.h>
#define MAX 2000001
#define CMAX 10000

int main(){
  static int n;
  static int A[MAX],C[CMAX+1],B[MAX];
  static int i,j;


  scanf("%d",&n);
  for(i=0;i<CMAX+1;i++){
    C[i]=0;
  }

  for(i=0;i<MAX+1;i++){
    B[i]=0;
  }

  
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
    C[A[i+1]]++;
  }

  for(i=1;i<=CMAX;i++){
    C[i]=C[i]+C[i-1];
  }

  for(j=n;j>0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i!=n)printf(" ");
  }
  printf("\n");

  return 0;
}
   
   
