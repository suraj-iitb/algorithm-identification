#include<stdio.h>
#define N 10000



int main(){
  int S[N];
  int n,T,i,q,result;
  int sum = 0;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&T);
    result = search(S, n, T);
    if(result != -1){
      sum++;
    }
  }

  printf("%d\n",sum);

  return 0;
  
}

  int search(int S[], int n, int key){
  int i = 0;
  S[n] = key;
  while(S[i] != key){
  i++;
}
  if(i >= n){
  return -1;
}
  return i;
}

