#include <stdio.h>
#define N 100
int main(){
  int A[N];
  int i,j;
  int key,n;

  scanf("%d",&n);
  for(i=0;i<n;i++){scanf("%d",&A[i]); }

  for(i=1;i<n;i++){
    for(j=0;j<n-1;j++){printf("%d ",A[j]);}
    printf("%d\n",A[j]);
    key=A[i];
    j=i-1;
    while(j>=0 && A[j]>key){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;
  }

   for(j=0;j<n-1;j++){printf("%d ",A[j]);}
    printf("%d\n",A[j]);
    
  return 0;
}

