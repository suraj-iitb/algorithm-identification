#include <stdio.h>
#define N 10000
int main(){
  int i,j,x,y,S[N],T[N],c=0;
  scanf("%d",&x);
  for(i=0;i<x;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&y);
  for(j=0;j<y;j++){
    scanf("%d",&T[j]);
    
  }
  for(j=0;j<y;j++){
    for(i=0;i<x;i++){
      if(S[i]==T[j]){
	c++;
	break;
      }
    }
  }

  printf("%d\n",c);
  return 0;
}

