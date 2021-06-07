#include <stdio.h>

int search(int);

int S[100000], n = 0;
int main(){
  int m = 0, q = 0, left = 0, right = 0, mid = 0;
  int i = 0, j = 0, cnt = 0;
  int T[50000];

  /*Input S[N]*/
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }
  
  /*Input T[N]*/
  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
  }

  /*Search*/
  for(i = 0; i < q; i++){
    m = search(T[i]);
    if(m != n)cnt++;
  }
  /*Print*/
  printf("%d\n",cnt);

  return 0;
}

int search(int key){
  int mid = 0, left = 0, right = 0;
  
  left = 0;
  right = n;
  
  while(left < right){
    mid = (left + right)/2;
    if(S[mid] == key){
      return mid;
    }
    else if(key < S[mid]){
      right = mid;
    }
    else if(key > S[mid]){
      left = mid + 1;
    }
  }
  return n; 
}

