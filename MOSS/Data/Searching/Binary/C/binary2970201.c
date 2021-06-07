#include <stdio.h>
int bs(int);
int n, S[100000];
int main(){
  int q,T[50000],i,x=0;
  
    scanf("%d",&n);
  for(i = 0; i < n; i++)
    scanf("%d",&S[i]);
  
  scanf("%d",&q);
  for(i = 0; i < q; i++)
    scanf("%d",&T[i]);

  for(i = 0; i < q; i++){
    if(bs(T[i]) == T[i]) x++;
  }
  
  printf("%d\n",x);
  
  return 0;
}

int bs(int key){
  int l,r,m;
  l = 0;
  r = n;
   while(l<r){
      m = (l+r)/2;
      if(key == S[m])
	return key;
      else if(key < S[m]) r = m;
      else l = m+1;
   }
   return 0;
}

