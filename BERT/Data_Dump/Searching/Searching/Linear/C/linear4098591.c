#include<stdio.h>

int main(){
  int n,q,i,j,cnt=0;
  int S[10000];
  int T[500];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }
  for(j=0;j<q;j++){
    for(i=0;i<n;i++){
      if(T[j]==S[i]){
	cnt++;
	break;
      }
    }
  }
  printf("%d\n",cnt);
  return 0;
}
