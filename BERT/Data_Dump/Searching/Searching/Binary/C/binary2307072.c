#include<stdio.h>
#define n 100000
#define q 50000

int main(){

  int S[n],T[q];
  int l,r,x,y,count=0,i,m;

  scanf("%d",&x);
  for(i=0;i<x;i++)
    scanf("%d",&S[i]);

  scanf("%d",&y);
  for(i=0;i<y;i++)
    scanf("%d",&T[i]);

  for(i=0;i<y;i++){
    l=0;
    r=x;
    while(l<r){
      m=(l+r)/2;
      if(S[m]==T[i]){
	count++;
	break;
      }
      else if(T[i]<S[m])r = m;
      else l = m+1;
    }
  }
  
  printf("%d\n",count);

  return 0;
}
