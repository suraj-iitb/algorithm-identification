#include<stdio.h>

int judge(int S[], int n, int key){
  int i = 0;
  S[n] = key;
  while(S[i] != key) i++;
  return i != n;
}

int main(){
  int S[10001], i, n, q, key, sum = 0;
  scanf("%d",&n);
  for( i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for( i = 0; i < q; i++){
    scanf("%d",&key);
    if(judge(S, n, key)) sum++;
  }
  printf("%d\n",sum);
  
  return 0;
}
