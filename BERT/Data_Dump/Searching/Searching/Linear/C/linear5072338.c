#include<stdio.h>
int lS(int);
int n,q,cnt=0;
int S[100000],T[5000];
int main(){
  int i,j,k;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(j=0;j<q;j++){
    k=lS(j);
  }
  printf("%d\n",cnt);

  return 0;
}
int lS(int j){
  int i,key;
  i=0;
  S[n]=T[j];
  while(1){
    if(i==n)return 0;
    if(T[j]==S[i])break;
    i++;
  }
  cnt++;
}

