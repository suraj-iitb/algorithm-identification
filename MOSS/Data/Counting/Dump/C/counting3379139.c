#include <stdio.h>
#define MAX 2000005

int n,A[MAX],B[MAX];
void CountingSort(void){
  int i,j,C[MAX];
  for(i=0;i<MAX;i++){
   C[i]=0;
  }
  for(j=1;j<=n;j++){

    C[A[j]]++;
  }
  for(i=1;i<=MAX;i++){
    C[i]=C[i]+C[i-1];
  } 
  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}
int main(){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
  }
  CountingSort();
  for(i=1;i<n;i++){
    printf("%d ",B[i]);
 }
  printf("%d\n",B[n]);



  return 0;
}

