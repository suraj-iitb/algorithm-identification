#include<stdio.h>
#include<stdlib.h>

int main(){
  int n,S[10001],q,T[501],i,j,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
    if(S[i]<0 || S[i]>1000000000){
      exit(1);
      }
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
    if(T[i]<0 || T[i]>1000000000){
      exit(8);
      }
  }
  
  for(i=0;i<q;i++){
    for(j=0;j<n-1;j++){
      if(T[i]==S[j]){
	count++;
	break;
      }
    }
  }
  
  printf("%d\n",count);

  return 0;
}
