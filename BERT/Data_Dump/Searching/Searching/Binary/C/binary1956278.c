#include<stdio.h>

#define MAX 100000

int main(){
  int i,l,m,r,n,q,count,key,S[MAX],T[MAX];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++)
    scanf("%d",&T[i]);

  count = 0;
  for(i=0;i<q;i++){
    key = T[i];
    l = 0;
    r = n;
    while(l < r){
      m = (l + r) / 2;
      if(key == S[m]){
	count++;
	break;
      }
      else if(key < S[m])r = m;
      else if(key > S[m])l = m + 1;
    }
  }

  printf("%d\n",count);

  return 0;
}
