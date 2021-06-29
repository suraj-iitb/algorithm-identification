#include <stdio.h>
#include <stdlib.h>

int n, S[10000];

int linearSearch(int key){
  for(int i=0; i < n; i++){
    if(S[i] == key)return S[i];
  }
  return -1;
}

int main(){
  int r,q, T[10000], count=0, tan[10000];

  scanf("%d", &n);
  if(n>10000)exit(1);
  for(int i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  if(q>500)exit(1);
  for(int j = 0; j < q; j++){
    scanf("%d", &T[j]);
  }

  for(int i = 0; i < q; i++){
    r = linearSearch(T[i]);
    if(r != -1){
      tan[count] = r;
      count++;
    }
  }

  printf("%d\n", count);
  return 0;
}

