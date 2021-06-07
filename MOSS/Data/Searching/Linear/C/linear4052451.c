#include <stdio.h>
#include <stdlib.h>
#define NOT_FOUND -1

int linearSearch(int);

int n,*S,q,*T;
int main(){
  int C=0,i,j,key;
  scanf("%d",&n);
  S=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  
  scanf("%d",&q);
  T=(int *)malloc(sizeof(int)*q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);

  

  while(j!=q){
    key=T[j];
    if(linearSearch(key)!=NOT_FOUND) C++;
    j++;
  }
  
  printf("%d\n",C);
  return 0;
}

int linearSearch(int key){
  int i=0;
  S[n]=key;
  while(S[i]!=key){
    i++;
    if(i==n) return NOT_FOUND;
  }
  return i;
}

