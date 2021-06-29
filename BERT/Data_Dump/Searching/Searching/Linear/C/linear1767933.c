#include <stdio.h>
 
int main(){
 
  int i,j,n,S[10000],q,T[500],count=0;
 
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
 
  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
 
  for(j=0;j<q;j++){
    i=0;
    S[n] = T[j];
    while(S[i]!=T[j]){
      i++;
    }
    if(i!=n){
      count++;
    }
  }
 
  printf("%d\n",count);
  return 0;
}
