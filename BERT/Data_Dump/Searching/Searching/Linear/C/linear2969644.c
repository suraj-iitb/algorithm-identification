#include <stdio.h>
#include <stdlib.h>
int main(){
  int key,S[10001],n,q,T[500],i,j,k,cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
    S[n]=T[i];
    key=S[n];
    j=0;
    k=0;
    while(S[j]!=key){
      j++;
      if(j==n){
	k++;
	break;
      }
    }
    if(k==0)cnt++;
  }
  printf("%d\n",cnt);
  return 0;
}

