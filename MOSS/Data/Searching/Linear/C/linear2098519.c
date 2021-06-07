#include <stdio.h>

int Search(int key, int S[], int n){
  int i;
  for(i = 0; i < n; i++){
    if(S[i] == key) return 1;
  }
  return 0;
}
 
int main(){
  int n, S[10000], q, key, count = 0;
  int i;
 
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &key);
    if(Search(key, S, n)) count++;
  }

  printf("%d\n", count);

  return 0;
}
