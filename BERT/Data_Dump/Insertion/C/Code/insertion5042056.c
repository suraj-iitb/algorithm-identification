#include <stdio.h>

int main(){
  int i,j,k,n,v,A[1000];
  scanf("%d",&n);
  for(i=0;n>i;i++){
    scanf("%d",&A[i]);
  }
  for(i=1;n-1>=i;i++){
    for(k=0;k<n;k++){
      printf("%d",A[k]);
      if(k+1<n)printf(" ");
    }
    printf("\n");
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
  }
  for(j=0;n>j;j++){
    printf("%d",A[j]);
    if(j+1<n) printf(" ");
  }
  printf("\n");
  return 0;
}

