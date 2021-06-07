#include <stdio.h>
#define N 100001
#define Q 1000

int linear(int);
int n;
int S[N];

int main(){
  int q, i, c=0, flag;
  int T[Q]={};

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }

  for(i=0; i<q; i++){
    flag = linear(T[i]);
    if(flag == 1){
      c++;
    }
  }
    
  printf("%d\n",c);

  return 0;
}

int linear(int key){
  int i=0;
  S[n]=key;

  while(S[i] != key){
    i++;
    if(i == n){
      return 0;
    }
  }
  return 1;
}
