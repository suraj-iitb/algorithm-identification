#include <stdio.h>
#define N 2000001

int A[N],B[N],C[N];
int n;


void CountingSort(int k){
  
  int i,j;
  
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
}





int main(){
  int i,m=0;
 


  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(m<A[i]){
      m=A[i];
    }
  }  
  CountingSort(m);

  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i<n) printf(" ");
  }

  printf("\n");
  return 0;
  
}
