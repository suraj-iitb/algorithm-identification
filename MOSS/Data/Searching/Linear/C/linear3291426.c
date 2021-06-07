#include<stdio.h>
int linearSearch(int*,int,int);

int main(){
  int n,q;
  int i=0;
  int count=0;
  scanf("%d",&n);
  int S[n];
  for(i=0;i < n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  int T[q];
  for(i=0;i < q;i++){
    scanf("%d",&T[i]);
    if(linearSearch(S,T[i],n) == 1) count++;
  }
  printf("%d\n",count);
  return 0;
}

int linearSearch(int *s,int k,int n){
  int i = 0;
  s[n]=k;
  while(s[i] != k){
    i++;
    if(n==i)
      return 0;
  }
  return 1;
}

