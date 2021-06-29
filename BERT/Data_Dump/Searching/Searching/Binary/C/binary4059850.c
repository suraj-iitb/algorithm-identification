#include <stdio.h>

int S[1000000],n;

int b_search(int key){
  int l =0;
  int r = n;
  int m;
  while (l < r){
    m = (l + r)/2;
    if(key == S[m])return 1;
    if (key > S[m])l = m + 1;
    else if (key < S[m])r = m;
  }
  return 0;
}

int main(){
  int i,q,k,sum=0;
  scanf("%d",&n);
  for( i=0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&k);
    if(b_search(k))sum++;
  }
  printf("%d\n",sum);
  return 0;
}

