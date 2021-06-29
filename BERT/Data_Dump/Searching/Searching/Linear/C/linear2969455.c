#include <stdio.h>

int main(){
  int a,i,j,k,n,q,ans=0;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  int T[n];
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i]==S[j]){
	ans++;
	break;
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}

