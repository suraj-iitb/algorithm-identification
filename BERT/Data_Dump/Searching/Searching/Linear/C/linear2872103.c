#include <stdio.h>

#define M 10000

int main(){
  int n,q,i,j,S[M],T,res = 0;
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i = 0 ; i < q ; i++){
    scanf("%d",&T);
    for(j = 0 ; j < n ; j++){
      if(T == S[j]){
        ++res;
        break;
      }
    }
  }
  printf("%d\n",res);
  return 0;
}
