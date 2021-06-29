#include<stdio.h>
  
int main(){
  int i, j, n, q, c=0, l, r, m;
  int S[100001], T[50001];
  
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }
    
  for(i=0; i<q; i++){
    l = 0;
    r = n;
    while(l < r){
      m = (l + r)/2;
      if(S[m] == T[i]){
        c++;
        break;
      }
      else if(S[m] < T[i]) l = m+1;
      else  r = m;
    }
  }
  printf("%d\n",c);
  return 0;
}
