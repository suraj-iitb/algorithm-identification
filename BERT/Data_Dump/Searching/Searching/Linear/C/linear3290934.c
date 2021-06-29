#include <stdio.h>

int search(int[],int,int);

int main(){
  int S[10001],T,i,j,n,q,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T);
    if(search(S,n,T))count++;
  }
  printf("%d\n",count);
  return 0;
}


int search(int S[],int n,int T){
  int i=0;

  S[n]=T;

  while(S[i] != T)i++;

  return i != n;
}

