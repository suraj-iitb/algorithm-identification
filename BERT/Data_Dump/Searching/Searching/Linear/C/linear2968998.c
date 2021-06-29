#include<stdio.h>

int main(){

  int n,q,i,j,C=0;
  int S[100000];
  int T[500];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i]==S[j]){
	C++;
	break;
      }
    }
  }
  printf("%d\n",C);
  return 0;
}

