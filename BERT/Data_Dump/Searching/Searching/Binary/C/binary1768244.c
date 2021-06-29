#include <stdio.h>
#define N 100000
#define Q 100000

int binary(int);
int n;
int S[N];

int main(){
  int q, i, c=0, flag;
  int T[Q]={};

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }

  for(i=0; i<q; i++){
    flag = binary(T[i]);
    if(flag == 1){
      c++;
    }
  }
    
  printf("%d\n",c);

  return 0;
}

int binary(int key){
  int mid, left, right;
  left = 0;
  right = n;
  while (left < right){
    mid = (left + right)/2;
  if(S[mid] == key){
    return  1;
  } else if(key < S[mid]){
    right = mid;
  } else {
    left = mid + 1;
  }
  }
    return 0;
}
