#include <stdio.h>

int linerSearch(int *,int,int);

int main(){
  int S[10000],q,i,n,t,c=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    if(linerSearch(S,n,t) == 1)c++;
  }
  printf("%d\n",c);
  return 0;
}

int linerSearch(int *S,int n,int key){
  int i=0;
  S[n]=key;
  while(S[i]!=key){
    i++;
    if(i==n) return 0;
  }
  return 1;
}

