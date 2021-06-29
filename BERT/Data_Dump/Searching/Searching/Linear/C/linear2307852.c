#include<stdio.h>
#include<stdlib.h>

int linearSearch(int*,int);

  int n;
  
int main(){
  int i,q,*S,*T,C=0;
  scanf("%d",&n);
  S=(int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  T=(int*)malloc(sizeof(int)*(q+1));
  for(i=0;i<q;i++)
    scanf("%d",&T[i]);
  for(i=0;i<q;i++){
    C+=linearSearch(S,T[i]);
  }
  printf("%d\n",C);
  return 0;
}

int linearSearch(int *S,int key){
  int i=0;
  S[n]=key;
  while(S[i]!=key){
    i++;
  }
  if(i==n){
    return 0;
  }
  else
    return 1;
}
