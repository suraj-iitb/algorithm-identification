#include <stdio.h>

int main(){
  int a,n,q,i,j,count;
  int S[10000],T[10000];
  count=0;

  //*数列Sの個数*//
  scanf("%d",&n);
  if(n<0||n>10000){
    printf("error\n");
  }
  //*数列Sの要素*//
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
    if(S[i]<0||S[i]>1000000000){
      printf("error\n");
    }
  }

  while(1){
    scanf("%d",&q);
    for(i=0;i<q;i++){
      scanf("%d",&T[i]);
      a=T[i];
      for(j=0;j<n;j++){
        if(a==S[j]){
          count++;
          break;
        }
      else continue;
      }
    }
    printf("%d\n",count);
    break;
  }

  return 0;
}
