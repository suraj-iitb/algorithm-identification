#include <stdio.h>

int linearSearch();

int main(){
  int s,t,i,j,A[10001],key,C=0;
  scanf("%d",&s);
  for(i=0; i<s; i++) scanf("%d",&A[i]);
  scanf("%d",&t);
  for(j=0; j<t; j++){
    scanf("%d",&key);
    if(linearSearch(key, s, A) != -1) C++;
  }
  printf("%d\n",C);
}

int linearSearch(int key, int n, int A[]){
  int i=0;
  A[n] = key;
  while(A[i] != key) i++;
  if(i!=n) return i;
  else return -1;
}
