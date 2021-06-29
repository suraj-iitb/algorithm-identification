#include<stdio.h>

int linearSearch(int a, int n, int S[]){

  for(int i=0; i<n; i++){
    if(a == S[i]) return 1;
  }

  return 0;
}

int main(){

  int i, n, q;
  scanf("%d", &n);
  int S[n];
  for(i=0; i<n; i++) scanf("%d", &S[i]);
  scanf("%d", &q);
  int T[n];
  for(i=0; i<n; i++) scanf("%d", &T[i]);

  int anw = 0;

  for(i=0; i<q; i++){
    if(linearSearch(T[i], n, S)) anw++;
  }

  printf("%d\n", anw);
  
  return 0;
}
