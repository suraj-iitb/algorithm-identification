#include<stdio.h>
int linearSearch(int *,int,int);

int main(){
  int i,j,n,q,S[10000],T[10000],count=0;
    scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
    }
  
  for(i=0;i<q;i++){
  if(linearSearch(S,n,T[i])!=0){
    count++;
  }
  }
  
  printf("%d\n",count);
  
  return 0;
}

int linearSearch(int *S,int n,int x){
  int i=0,count;
  S[n]=x;
  while(S[i]!=x){
    i++;
    if(i==n){
      return 0;
    }
  }
  return 1;
  }
