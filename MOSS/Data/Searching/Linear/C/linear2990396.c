#include<stdio.h>

int main(){
  int n,q,i,j,count=0;

  scanf("%d",&n);
  int S[n];
  for(i=0 ; i<n ; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  int T[q];
  for(j=0 ; j<q ; j++){
    scanf("%d",&T[j]);
  }

  for(i=0 ; i<q ; i++){
    for(j=0 ; j<n ; j++){
if(S[j] == T[i]){
  count++;
  break;
}
}
}

printf("%d",count);
printf("\n");

return 0;
}

