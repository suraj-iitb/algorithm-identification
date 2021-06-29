#include <stdio.h>
#define N 10000
int main(){
  int a,b,i,j,x,y,S[N],T[N],count=0;
  scanf("%d",&x);
  for(i=0;i<x;i++){
    scanf("%d",&a);
    S[i]=a;
  }
  scanf("%d",&y);
  for(j=0;j<y;j++){
    scanf("%d",&b);
    T[j]=b;
  }
  for(j=0;j<y;j++){
    for(i=0;i<x;i++){
      if(S[i]==T[j]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

