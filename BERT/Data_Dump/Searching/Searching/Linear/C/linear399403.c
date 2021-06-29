#include<stdio.h>

int main(){
  int i, j, n, q, c=0;
  int S[10001], T[501];
  
  scanf("%d",&n);
  for(i=1; i<=n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=1; i<=q; i++){
    scanf("%d",&T[i]);
  }
  for(i=1; i<=n; i++){
    for(j=1; j<=n; j++){
      if(i != j && S[i] == S[j]) S[j]=0;
    }
  }

  for(i=1; i<=n; i++){
    if(i>1 && S[i]==0)continue;
    for(j=1; j<=q; j++){
      if(S[i] == T[j]) c++;
    }
  }
  printf("%d\n",c);
  return 0;
}
