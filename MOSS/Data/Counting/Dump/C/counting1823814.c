#include <stdio.h>
#define len 10001
#define MAX 2000001

int A[MAX];
int B[MAX];
int C[len];

int main(){

  int i,n;
  for(i=0;i<len;i++){
    C[i]=0;
  }
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }
  for(i=1;i<=n;i++){
    C[A[i]]++;
  }

  for(i=1;i<=len;i++){
    C[i]=C[i]+C[i-1];
  } 
  for(i=n;i>=1;i--){
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }

  for(i=1;i<=n;i++){
    if(i>1) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  return 0;
}


    
  
