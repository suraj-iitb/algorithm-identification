#include<stdio.h>

#define M 100000


int main(void){
  int i,l,m,r,n,q,cnt=0,key,S[M],T[M];

  scanf("%d",&n);
  
  
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++)
    scanf("%d",&T[i]);


  for(i=0;i<q;i++){
    key = T[i];
    l = 0;
    r = n;
    while(l < r){
      m = (l + r) / 2;
      
      if(key == S[m]){
	cnt++;
	break;
      }
      
      else if(key < S[m])r = m;
      else if(key > S[m])l = m + 1;
      
    }
  }

  printf("%d\n",cnt);
  
  return 0;
}

