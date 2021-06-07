#include <stdio.h>
int linearSearch(int n, int key, int A[]){
  int i;
  for(i = 0; i < n-1; i++){
    if(A[i] == key)return 1;
  }
  return 0;
}

int main(){
  int i, n, q, key, sum = 0;
  int S[10000];

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&S[i]);
  
  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&key);
    sum += linearSearch(n, key, S);
  }
 
  printf("%d\n",sum);

  return 0;
}

