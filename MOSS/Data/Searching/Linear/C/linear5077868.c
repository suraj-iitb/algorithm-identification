#include <stdio.h>

int main(){
  int i,j,n,q,same=0,g;

  scanf("%d",&n);

  int A[n+1];

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);

  int B[q];

  for(i=0;i<q;i++){
    scanf("%d",&B[i]);
  }

  for(j=0;j<q;j++){
    i=0;
    A[n]=B[j];
    while(A[i]!=B[j]){
      i++;
    }
    if(i!=n)same++;
  }

  printf("%d\n",same);

  return 0;
}
