#include <stdio.h>
#include <stdlib.h>

int main(){
  int n=100,i,j,v,A[n];

  scanf("%d",&n);
  if(n<1||n>100)
    exit(1);

  for(i = 0;i<n;i++){
    scanf("%d", &A[i]);
    if(A[i]<0||A[i]>1000)
      exit(1);
  }

  for(i=1; i<=n; i++){
    for(j=0;j<n;j++){
      printf("%d",A[j]);
      if(j<n-1)printf(" ");
    }
    printf("\n");
    if(i == n)break;
    v = A[i];
    j = i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1] = v;;
      }
  }
  return 0;
}
