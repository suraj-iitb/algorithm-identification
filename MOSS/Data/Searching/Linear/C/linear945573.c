#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 10000
#define Q 500
int main(){
  int i,n,q,j,S[N],T[Q],AI=0;
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
      if(S[j]==T[i]){
	AI++;
	break;
      }
    }
  }
  printf("%d\n",AI);
  
  
  return 0;
}
