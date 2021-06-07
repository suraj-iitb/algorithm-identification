#include<stdio.h>

int main(){
  int i,j,n,q,S[10001],T[501],count=0;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for (i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for (j=0;j<q;j++){
    for (i=0;i<n;i++){
      if (S[i]==T[j]){
	count++;
	break;
      }
    }
  }

  printf("%d\n",count);
  return 0;
}
