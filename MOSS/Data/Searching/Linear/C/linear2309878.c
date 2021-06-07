#include <stdio.h>
int main (){

  int n[10000],nc,q[500],qc,i,j,count=0;
  scanf("%d",&nc);
  for(i=0 ; i<nc ; i++){
    scanf("%d",&n[i]);
  }
  scanf("%d",&qc);
  for(i=0;i<qc;i++){
    scanf("%d",&q[i]);
    for(j=0;j<nc;j++){
      if(n[j]==q[i]){
        count++;
        break;
      }
    }
  }

  printf("%d\n",count);
  return 0;
}
