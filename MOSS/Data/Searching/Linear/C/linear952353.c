#include <stdio.h>

int i,c=0;

void LinearSearch(int *A,int key){
  int j=0;
  A[i]=key;
  while(A[j]!=key){
    j++;
  }
    if(j==i){
      return;
    }
    c++;
    return;
}

main(){
  int S[10000];
  int t,j,q,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
    for(j=0;j<q;j++){
      scanf("%d",&t);
      LinearSearch(S,t);
    }

    printf("%d\n",c);
    return 0;
}
