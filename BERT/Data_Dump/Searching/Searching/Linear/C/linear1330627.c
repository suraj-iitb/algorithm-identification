#include <stdio.h>
#define x 10000

int main(){
  int i,j,n,q,c,S[x],T[x],key;
  c =0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i]==S[j]) {c++; break;}
    }
  }
  printf("%d\n",c);
  return 0;
  
}
