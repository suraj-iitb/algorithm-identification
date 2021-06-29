#include <stdio.h>

#define NOT_FOUND 0

int linearSearch(int *,int,int);

int main(){
  int i,n,q,a,sum=0;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  int T[n];
  for(i=0;i<q;i++)
    scanf("%d",&T[i]);

  for(i=0;i<q;i++){
    a=linearSearch(S,T[i],n);
    if(a!=0) sum++;
  }
  printf("%d\n",sum);
  return 0;
}

int linearSearch(int *S,int key,int n){
  int i = 0;
  S[n]=key;
  if(S[0]==key) return 1;
  while(S[i]!=key){
    i++;
    if(i==n) return NOT_FOUND;
  }
  return i;
}
