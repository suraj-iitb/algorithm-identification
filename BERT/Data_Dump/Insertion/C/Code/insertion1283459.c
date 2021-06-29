#include <stdio.h>
#define N 1000
main(){
  int i,j,l,v,t;
  int A[N];
  scanf("%d",&l);
  for(i=0;i<l;i++){
    scanf("%d", &A[i]);
  }
  for(i=1;i<=l;i++){
  for(t=0;t<l;t++){
    printf("%d",A[t]);
    if(t != l-1) printf(" ");
    else printf("\n");
  }
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;

  }

  return 0;
}
