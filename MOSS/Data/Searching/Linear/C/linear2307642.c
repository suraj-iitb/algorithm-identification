#include <stdio.h>
int linearSearch(int);
int n,S[10001];
int main(){
  int i,q,count=0;
  int judge;
  int T[500];
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)
    scanf("%d",&T[i]);
  for(i=0;i<q;i++){
    judge=linearSearch(T[i]);
  if(judge >= 0)
    count++;
  }
  printf("%d\n",count);
  
  return 0;
}

int linearSearch(int key){
  int i=0;

  S[n]=key;
  while(S[i] != key)
    i++;
  if(i == n)
    return -5;
  return i;
}
