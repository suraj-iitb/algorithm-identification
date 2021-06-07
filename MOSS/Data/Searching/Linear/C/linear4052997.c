#include<stdio.h>

int search(int S[],int n,int T){
  
  int i=0;
  S[n]=T;
  while(S[i] != T)i++;
  return i != n;
  
}

int main(){
  
  int i,n,q,T,C=0,S[10000+1];
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T);
    if(search(S,n,T))C++;
  }
  printf("%d\n",C);
  
  return 0;
}

