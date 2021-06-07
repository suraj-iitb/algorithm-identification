#include<stdio.h>
#include<stdlib.h>
int linearSearch(int n,int key,int *S);
int main(){
  int n,*S,q,*T,i,N,count=0;
  scanf("%d\n",&n);
  S=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d\n",&q);
  T=(int *)malloc(q*sizeof(int));
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    N=linearSearch(n,T[i],S);
    if(N!=77777){
      count++;
    }
  }
  printf("%d\n",count);
  return 0;
}
int linearSearch(int n,int key,int *S){
  int i=0;
  S[n]=key;
  while(S[i]!=key){
    i++;
  }
  if(i>=n) return 77777;
  return i;
}

