#include <stdio.h>
#define MAX 10000

int S[MAX], n;
int linearSearch(int);

int main(){
  int i, q, count = 0, T[MAX];

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
    if(linearSearch(T[i]) == 1) count++;
  }
  printf("%d\n",count);

  return 0;
}

int linearSearch(int t){
  int i;
  for(i = 0; i < n; i++){
    if(S[i] == t) return 1;
  }

  return 0; 
}
