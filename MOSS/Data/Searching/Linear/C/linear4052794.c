#include <stdio.h>
#define MAX 10000

int linearSearch(int,int);
int S[MAX];

int main(){

  int i,n,q,T,kosu=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) {
    scanf("%d",&T);
    if(linearSearch(T,n)==1) kosu++;
     }
  printf("%d\n",kosu);

  return 0;
}

int linearSearch(int key,int n){

  int i=0;
  S[n]=key;
  while(S[i]!=key){
    i++;
    if(i==n) return 0;
  }
  return 1;
}

