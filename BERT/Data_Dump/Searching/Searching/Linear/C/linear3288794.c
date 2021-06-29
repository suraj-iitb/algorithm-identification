#include<stdio.h>

int main(){
  int n,q,i,j,count=0;
  
  scanf("%d",&n);
  int S[10000];

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  
  scanf("%d",&q);
  int T[500];

  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }

  
  for(j=0;j<q;j++){
    i = 0;
    while(i<n && S[i] != T[j]){
      i++;
    }
    if(i == n){
    }else{
      count++;
    }
  }

  printf("%d\n",count);

  return 0;
}

