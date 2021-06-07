#include <stdio.h>

int binarySearch(int);

int n;
int count=0;
int S[100000], T[50000];

int main(){
  int i;
  int q;
  
  //Sのデータの入力
  scanf("%d", &n);
  for( i=0 ; i<n ; i++){
    scanf("%d", &S[i]);
  }
  
  //Tのデータの入力&探索
  scanf("%d", &q);
  for( i=0 ; i<q ; i++){
    scanf("%d", &T[i]);
    if(binarySearch(T[i]) == 1){
      count++;
    }
  }
  printf("%d\n",count);
  return 0;
}

int binarySearch(int key){
  int left, right, mid;
  
  left = 0;
  right = n;
  
  while(left < right){
    mid = (left + right) / 2;
    if(S[mid] == key){
      return 1;
    }else if(key < S[mid]){
      right = mid;
    }else{
      left = mid + 1;
    }
  }
  return 0;
}

