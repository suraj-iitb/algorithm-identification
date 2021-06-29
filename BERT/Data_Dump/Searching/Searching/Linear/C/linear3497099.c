#include<stdio.h>
#define LENn 10000
#define LENq 10000

int main(){
  int n,s[LENn],q,t[LENq];
  scanf("%d",&n);
  for(int i = 0; i < n; i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(int i = 0; i < q; i++){
    scanf("%d",&t[i]);
  }
  int cnt=0;
  for(int i = 0; i < q; i++){
    for(int j = 0; j < n; j++){
      if(s[j]==t[i]) {
        cnt++;
        break;
      }
    }
  }

  printf("%d\n",cnt);

}

