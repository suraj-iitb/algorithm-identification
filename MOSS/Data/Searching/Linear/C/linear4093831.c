#include <stdio.h>
#define N 10000
int main() {
  int i,n,S[N],q,T[N],cnt=0,j;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&T[i]);
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(S[j]==T[i]){
	cnt++;
	break;
      }
    }
  }
  printf("%d\n",cnt);
  return 0;
}
