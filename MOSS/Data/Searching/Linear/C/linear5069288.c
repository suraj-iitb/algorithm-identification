#include <stdio.h>
#include <stdlib.h>

int linearSearch (int);
int n,q,*S,*T;
int main(){
  int i,key,count=0;
  
  scanf("%d",&n);
  S=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

   scanf("%d",&q);
  T=(int *)malloc(sizeof(int)*n);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    key=T[i];
    if(linearSearch(key)!=0)count++;
  }
  printf("%d\n",count);
  return 0;
}
  
int linearSearch(int key){
  int i=0;
  while(S[i]!=key){
    if(i==n)return 0;
    i++;
  }
  return 1;
}

