#include<stdio.h>

int linearSearch(int S[],int n,int key){
  int i=0;
  S[n] = key;
  while(S[i] != key)i++;
  return i != n;
}

int main(){
  int i,n,S[10000+1],q,key,C=0;
  scanf("%d",&n);
  for(i = 0;i < n;i++)scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(linearSearch(S,n,key))C++;
  }
  printf("%d\n",C);
  return 0;
}

