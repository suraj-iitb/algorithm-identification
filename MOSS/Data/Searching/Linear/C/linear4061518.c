#include<stdio.h>

int LinerSearch(int*,int,int);

int main(){
  int i,n,j,key,S[10000],t=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&j);
  for(i=0;i<j;i++){
    scanf("%d",&key);
    if(LinerSearch(S,n,key)==1)
      t++;
  }
  printf("%d\n",t);
  return 0;
}

int LinerSearch(int *S,int n,int key){
  int i=0;
  S[n] = key;
  while(S[i]!=key){
    i++;
    if(i==n)return 0;
  }
  return 1;
}

