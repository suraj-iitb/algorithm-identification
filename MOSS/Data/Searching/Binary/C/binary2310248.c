#include<stdio.h>

int S[1000000], n;

int binary(int key){
  int left = 0;
  int right = n;
  int mid;

  while(left < right){
    mid = (left + right) / 2;
    if(key == S[mid]) return 1;
    if(key > S[mid]) left = mid + 1;
    else if(key < S[mid]) right = mid;
  }
  return 0;
}

int main(){
  int i, q, key, sum = 0;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&key);
    if(binary(key)) sum++;
  }
  printf("%d\n",sum);

  return 0;
}
