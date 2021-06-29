#include <stdio.h>

int main(){
  int i;
  int n,q;
  int S[100000],T[50000];
  int cnt=0;
  int f,c,l,key;

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i = 0 ; i < q ; i++){
    scanf("%d",&T[i]);
  }

  for(i = 0 ; i < q ; i++){
    key = T[i];
    f = 0;
    l = n;
    while(f < l){
      c = (f+l)/2;
      if(key == S[c]){
        cnt++;
        break;
      }
      else if(key > S[c]){
        f = c+1;
      }
      else l = c;
    }
  }

  printf("%d\n",cnt);

  return 0;
}
