#include<stdio.h>
int main(){
  int n;
  int S[10001];
  int q;
  int T[501];
  int i,j;
  int ans=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);

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

