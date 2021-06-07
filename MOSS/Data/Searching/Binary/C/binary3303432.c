#include<stdio.h>

int S[1000000],n;

int search(int);

int main(){
  int k,q,i,j,C = 0;
  
  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&S[i]);
  
  scanf("%d",&q);
  for(j = 0; j < q; j++){
    scanf("%d",&k);
    if(search(k)) C++;
  }

  printf("%d\n",C);
  return 0;
}

int search (int k){
  int right = n,left = 0,mid;
  
  while(left < right){
      mid = (left + right) / 2;
      if(k == S[mid]) return 1;
      else if(k > S[mid]) left = mid + 1;
      else right = mid;
  }
  return 0;
}

