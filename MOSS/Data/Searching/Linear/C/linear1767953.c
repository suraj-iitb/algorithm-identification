#include<stdio.h>

#define N 1000000

int main(){
  int n,q,C=0;
  int S[N],T[N];
  int i,j,key;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++)
    scanf("%d",&T[i]);

  for(i=0;i<q;i++){
    key=T[i];
    j=0;
    while(j<n){
      for(j=0;j<n;j++){
	if(key == S[j]){
	  C++;
	  j=n;
	  break;
	}
      }
    }
  }
  printf("%d\n",C);
  return 0;
}
