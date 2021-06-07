#include<stdio.h>
int Search(int S[],int n,int T){
  int i=0;
  S[n]=T;
  while(S[i] != T)i++;
  return i != n;
}

int main(){
  int n,S[10000+1],q,T,i,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T);
    if( Search(S, n, T))
       count++;
  }
  printf("%d\n",count);
  return 0;
}

