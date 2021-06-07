#include<stdio.h>

int S[10000];
int N;

int linearSearch(int);

int main(){
  int q, T[500], i, c = 0;

  scanf("%d",&N);
  for(i = 0 ; i < N ; i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i = 0 ; i < q ; i++){
    scanf("%d",&T[i]);
    c += linearSearch(T[i]);    
  }
  printf("%d\n",c);
  return 0;
}

int linearSearch(int key){
  int i = 0;
  S[N] = key;
  while(S[i] != key){
    i++;
    if(i == N)
      return 0;
  }  
  return 1;
}
