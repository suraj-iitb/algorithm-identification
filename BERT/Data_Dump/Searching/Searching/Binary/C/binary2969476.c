#include<stdio.h>
#include<stdlib.h>

int C = 0;

void binary_search(int *s, int size, int t){
  int l, m, r;

  l = 0;
  r = size - 1;

  while(l <= r){
    m = (r + l)/2;

    if(s[m] == t){
      C++;
      break;
    }
    else if(s[m] < t){
      l = m +1;
    }
    else{
      r = m -1;
    }
  }
};

int main(){

  int *S, *T,n,N,i,j;

  scanf("%d",&n);
  S = (int *)malloc(sizeof(int)*n);

  for(i=0; i<=n-1; i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&N);
  T = (int *)malloc(sizeof(int)*N);
  for(i=0; i<=N-1; i++){
    scanf("%d",&T[i]);
  }

  //二分探査
  for(i=0;i<=N-1; i++){
    binary_search(S, n, T[i]);
  }


  printf("%d\n",C);

  return 0;
}
