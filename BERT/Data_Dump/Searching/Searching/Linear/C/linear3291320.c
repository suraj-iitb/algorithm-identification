#include<stdio.h>
#define MAX 10000
#define TRUE 1
#define FALSE 0

int linearSearch(int,int);
int S[MAX];
int main(){
  int i, n, q, T[MAX], C = 0;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }
  for(i=0; i<q; i++){
  if(linearSearch(T[i],n) == TRUE) C++;
  }

  printf("%d\n",C);
  return 0;
}

int linearSearch(int key,int n){
  int i = 0;
  while(key != S[i]){
    i++;
    if(i == n) return FALSE;
  }
  return TRUE;
}

