#include<stdio.h>

int linearSearch(int A, int N, int LS[]){

  for(int i=0; i<N; i++){
    if(A == LS[i]) 
    return 1;
  }

  return 0;
}

int main(){

  int i, N, m;
  scanf("%d", &N);
  int LS[N];
  for(i=0; i<N; i++) scanf("%d", &LS[i]);
  scanf("%d", &m);
  int T[N];
  for(i=0; i<N; i++) scanf("%d", &T[i]);

  int search = 0;

  for(i=0; i<m; i++){
    if(linearSearch(T[i], N, LS)) 
    search++;
  }

  printf("%d\n", search);
  
  return 0;
}
