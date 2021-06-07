#include <stdio.h>

int main(){

int i,j,n,q;
int k=0;
 int s[10000];
 int t[500];
  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);

  for(i = 0; i < q; i++){
    scanf("%d",&t[i]);
  }

  for(i = 0; i < q; i++){
    for(j = 0; j < n; j++){
      if(s[j] == t[i]){
    k=k+1;
    break;
      }
    }
  }

  printf("%d\n",k);

  return 0;
}

