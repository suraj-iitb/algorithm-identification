#include <stdio.h>
 
int main(){
  int n,q,i,key,l,u,m;
  int S[100000],ans = 0;
 
  scanf("%d" ,&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d" , S + i);
  }
 
  scanf("%d" ,&q);
  for(i = 0 ; i < q ; i++){
    scanf("%d" ,&key);
    l = 0; u = n;
    while(u >= l){
      m = (l + u) / 2;
 
      if(S[m] == key){
    ans++;
    break;
      }
 
      if(S[m] < key){
    l = m+1;
      }else{
    u = m-1;
      }
    }
  }
  printf("%d\n" ,ans);
 
  return 0;
}

