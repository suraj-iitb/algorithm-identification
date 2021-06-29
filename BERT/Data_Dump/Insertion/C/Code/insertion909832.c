#include<stdio.h>

#define N 100
 
int main(){
  int i,j,k,n,key,A[N];
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  for(i=0;i<n-1;i++) printf("%d ",A[i]);
  printf("%d\n",A[i]);


  for(i=1;i<n;i++){
    key = A[i];
    j = i - 1;
    while(j>=0 && A[j]>key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    for(k=0;k<n-1;k++) printf("%d ",A[k]);
    printf("%d\n",A[k]);
  }
  return 0;
}
