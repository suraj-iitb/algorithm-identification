#include<stdio.h>

int main(){
  int ns,nt,i,j;
  int count=0;

  scanf("%d",&ns);
  int S[ns];
  for(i=0 ; i<ns ; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&nt);
  int T[nt];
  for(j=0 ; j<nt ; j++){
    scanf("%d",&T[j]);
  }

  for(i=0 ; i<nt ; i++){
    for(j=0 ; j<ns ; j++){
if(S[j] == T[i]){
  count++;
  break;
}
}
}

printf("%d\n",count);


return 0;
}

