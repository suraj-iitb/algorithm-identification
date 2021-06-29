#include <stdio.h>

int main(){
  int i,j,n,A[100],v,k;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }
  for(i=1;i<=n;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
    for(k=1;k<=n;k++){
      printf("%d",A[k]);
      if(k==n) printf("\n");
      else printf(" ");
    }
  }
  return 0;
}
