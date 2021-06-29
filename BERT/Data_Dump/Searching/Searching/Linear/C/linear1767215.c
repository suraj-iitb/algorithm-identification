#include <stdio.h>
#define MAXn 10000
#define MAXq 500

int main(){
  int Snum[MAXn],Tq[MAXq],cnt=0,i,j,Sn,Tqn;
  
  scanf("%d",&Sn);
  for(i=0;i<Sn;i++){
    scanf("%d",&Snum[i]);
  }
  scanf("%d",&Tqn);
  for(i=0;i<Tqn;i++){
    scanf("%d",&Tq[i]);
  }
  for(j=0;j<Tqn;j++){
    for(i=0;i<Sn;i++){
      if(Snum[i]==Tq[j]){
        cnt++;
        break;
      }
    }
  }
  printf("%d\n",cnt);
  return 0;
}
