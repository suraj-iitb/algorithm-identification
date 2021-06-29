#include<stdio.h>
#define MAX 10000
int main(){
  int S[MAX],T[MAX];
  int i,j,cnt=0,n,q;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);
  
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i]==S[j]){
      cnt++;
      break;
      }
    }
  }
  printf("%d\n",cnt);

  return 0;
}
